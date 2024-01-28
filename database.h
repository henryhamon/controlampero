#include <Preferences.h>
#include <SQLite_ESP32.h>
#include <unordered_map>
#include "commons.h"

SQLite db;
Preferences preferences;

/*
* Example: Populate PatchStruct struct dynamically
*  PatchStruct patchToUpdate("01-2");
*  patchToUpdate.addSlotValue("slot_a", "A1");
*  patchToUpdate.addSlotValue("slot_a_txt", "Updated Slot A");
*  patchToUpdate.addSlotValue("slot_f", "F1");
*  patchToUpdate.addSlotValue("slot_f_txt", "Updated Slot F");

PatchStruct myPatch = getPatchData("01-2");
String slotAValue = myPatch.getSlotValue("slotA");
String slotATxtValue = myPatch.getSlotValue("slotATxt");
bool slotAStateValue = myPatch.getSlotValue("slotAState").toInt(); // Assuming it's a boolean represented as an integer in the database

*/
struct PatchStruct
{
    String patchName;
    std::unordered_map<String, String> slotValues;

    PatchStruct(String patchName) : patchName(patchName) {}

    void addSlotValue(String slotName, String slotValue)
    {
        slotValues[slotName] = slotValue;
    }

    String getSlotValue(const String &slotName) const
    {
        auto it = slotValues.find(slotName);
        if (it != slotValues.end())
        {
            return it->second;
        }
        return ""; // Return empty string if the slot name is not found
    }
};

void createTableIfNotExists()
{
    db.exec("CREATE TABLE patches ( \
            id INTEGER PRIMARY KEY AUTOINCREMENT, \
            slot_a VARCHAR(2), \
            slot_a_txt VARCHAR(15), \
            slot_a_state BOOLEAN, \
            slot_b VARCHAR(2), \
            slot_b_txt VARCHAR(15), \
            slot_b_state BOOLEAN, \
            slot_c VARCHAR(2), \
            slot_c_txt VARCHAR(15), \
            slot_c_state BOOLEAN, \
            slot_d VARCHAR(2), \
            slot_d_txt VARCHAR(15), \
            slot_d_state BOOLEAN, \
            slot_e VARCHAR(2), \
            slot_e_txt VARCHAR(15), \
            slot_e_state BOOLEAN, \
            slot_f VARCHAR(2), \
            slot_f_txt VARCHAR(15), \
            slot_f_state BOOLEAN, \
            slot_g VARCHAR(2), \
            slot_g_txt VARCHAR(15), \
            slot_g_state BOOLEAN, \
            slot_h VARCHAR(2), \
            slot_h_txt VARCHAR(2), \
            slot_h_state BOOLEAN, \
            patch VARCHAR(25) UNIQUE \
        ); \
        CREATE UNIQUE INDEX idx_patch ON patches(patch);");

    // Populate
    for (int i = 0; i < 100; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            String patchName = "P" + String(i, 10).padStart(2, '0') + "-" + String(j, 10);
            db.exec("INSERT INTO patches (patch) VALUES ('" + patchName + "');");
        }
    }
}

void updatePatch(const PatchStruct &patchUpdate)
{
    String updateQuery = "UPDATE patches SET ";
    for (const auto &entry : patchUpdate.slotValues)
    {
        updateQuery += entry.first + " = '" + entry.second + "', ";
    }
    updateQuery.remove(updateQuery.length() - 2);
    updateQuery += " WHERE patch = '" + patchUpdate.patchName + "';";
    db.exec(updateQuery);
}

/**
 * Retrieves the up and down patches for a given patch from the database.
 *
 * @param patch the patch to retrieve up and down patches for
 *
 * @return void
 *
 * @throws ErrorType if there is an error retrieving the patches from the database
 */
void getUpNDown(String patch)
{
    String query = "SELECT \
        p2.patch AS Up, p.patch AS Selected,p1.patch As Down \
    FROM \
        patches AS p \
    LEFT JOIN \
        patches AS p1 ON p1.id > p.id \
    LEFT JOIN \
        patches AS p1a ON p1a.id > p.id AND p1a.id < p1.id \
    LEFT JOIN \
        patches AS p2 ON p2.id < p.id \
    LEFT JOIN \
        patches AS p2a ON p2a.id < p.id AND p2a.id > p2.id \
    WHERE \
        p1a.id IS NULL \
        AND p2a.ID IS NULL ";
    query = query + " AND p.patch = '" + patch + "';";
    SQLiteRow row = db.getRow(query);

    if (row.isValid())
    {
        preferences.begin("controlampero_prefs", false);
        preferences.putInt("up", row.getString(0));
        preferences.putInt("down", row.getString(2));
        preferences.end();
    }
}

int getUpPatchFromPreferences()
{
    preferences.begin("controlampero_prefs", true);
    int upPatch = preferences.getInt("up", -1);
    preferences.end();
    return upPatch;
}

/**
 * Initialize the SQLite database and create the necessary table if it does not exist.
 */
void databaseInit()
{
    // Initialize SQLite database
    if (!db.begin("patches.db"))
    {
        Serial.println("Failed to initialize the database.");
        while (1)
        {
            delay(1000); // Halt the program
        }
    }

    // Check if the database file exists
    if (!db.exists())
    {
        Serial.println("Database does not exist. Creating...");
        createTableIfNotExists();
    }
}

PatchStruct loadPatchData(const String& patchName) {

    PatchStruct patchData("");
    // Fetch patch data from the database
    String query = "SELECT id, slot_a,slot_a_txt,slot_a_state,slot_b,slot_b_txt,slot_b_state,slot_c,slot_c_txt,slot_c_state,
        slot_d,slot_d_txt,slot_d_state,slot_e,slot_e_txt,slot_e_state,slot_f,slot_f_txt,slot_f_state,slot_g,slot_g_txt,slot_g_state,slot_h,slot_h_txt,
        slot_h_state, patch
        FROM patches WHERE patch = '" + patchName + "';";
    SQLiteResult result = db.query(query);

    if (result.getNumRows() > 0) {
        result.next();

        int col = 0;
        for (int i = 1; i <= 8; i++) {
            col++;
            patchData.addSlotValue("slot_" + String(char('a' + i - 1)), result.getString(col));
            col++;
            patchData.addSlotValue("slot_" + String(char('a' + i - 1)) + "_txt", result.getString(col));
            displayText[i - 1] = result.getString(col);
            col++;
            patchData.addSlotValue("slot_" + String(char('a' + i - 1)) + "_state", result.getInt(col));
        }
        // Populate PatchStruct with values from the database
        patchData.patchName = result.getString(25);
        // Populate PatchStruct with values from the database
    }

    return patchData;
}