
#ifndef DATABASE_H
#define DATABASE_H

#include <Preferences.h>
#include "commons.h"
#include <Arduino_JSON.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

extern const char* validSlotNames[24];

class Database {
public:
    struct PatchStruct {
        String patch;
        String slotValues[24];

        PatchStruct() {}

        PatchStruct(const String& patchName) : patch(patchName) {}

        void addSlotValue(const String& slotName, const String& slotValue) {
            int index = getSlotIndex(slotName);
            if (index != -1) {
                slotValues[index] = slotValue;
            }
        }

        String getSlotValue(const String& slotName) const {
            int index = getSlotIndex(slotName);
            return (index != -1) ? slotValues[index] : "";
        }

    private:
        int getSlotIndex(const String& slotName) const {
            if (slotName == "slot_a") return 0;
            else if (slotName == "slot_b") return 1;
            // ... continue for other slots ...
            else return -1; // Invalid slot name
        }
    };

    Database();

    String getCurrentPatch() const;
    String getCurrentSelectedPatch() const;
    String getPatchKey(const String& patch);
    PatchStruct getPatchData(const String& patch);
    PatchStruct searchPatchByName(const String& patchName);
    void setCurrentPatch(const String& patch);
    void savePatchData(const PatchStruct& patchData); 

private:
    Preferences preferences;
    const int maxPatches = 300;
    int currentIndex;
    String currentPatch;
    PatchStruct patches[300];

    void persistDatabase();
    String toJson(const PatchStruct& patchData);
    PatchStruct fromJson(const String& jsonString);

    String getPreviousPatch() const;
    String getNextPatch() const;
    void updatePatchLinks(const String& newPatchName);
    void changeCurrentPatch(const String& patchName);
};

#endif // DATABASE_H
//---------------------------------------------------------------------------------

const char* validSlotNames[24] = {
    "slot_a", "slot_a_txt", "slot_a_state",
    "slot_b", "slot_b_txt", "slot_b_state",
    "slot_c", "slot_c_txt", "slot_c_state",
    "slot_d", "slot_d_txt", "slot_d_state",
    "slot_e", "slot_e_txt", "slot_e_state",
    "slot_f", "slot_f_txt", "slot_f_state",
    "slot_g", "slot_g_txt", "slot_g_state",
    "slot_h", "slot_h_txt", "slot_h_state"
};

Database::Database() {
    currentIndex = -1; // Initialize currentIndex in the constructor
    preferences.begin("controlamp_prefs", false);

    if (!preferences.begin("controlamp_prefs", true)) {
        // Controlamp_prefs does not exist, initialize it

        // Add 3 empty PatchStructs with names "P00-1", "P00-2", and "P00-3"
        for (int i = 1; i <= 3; ++i) {
            String patchName = "P00-" + String(i, 10);
            PatchStruct emptyPatch(patchName);
            patches[i - 1] = emptyPatch;
        }

        // Populate
        for (int i = 0; i < 100; i++) {
            for (int j = 1; j <= 3; j++) {
                String patch_name = String(i, 10) + "-" + String(j, 10);
                if (i < 10) {
                    patch_name = "0" + patch_name;
                }
                savePatchData(PatchStruct(patch_name));
            }
        }

        changeCurrentPatch("P00-1");
        persistDatabase();
    } else if (preferences.begin("controlamp_prefs", false)) {
        persistDatabase();
    }
}

void Database::savePatchData(const PatchStruct& patchData) {
    int currentIndex = -1;
    for (int i = 0; i < maxPatches; ++i) {
        if (patches[i].patch == patchData.patch) {
            currentIndex = i;
            break;
        }
    }

}

String Database::getCurrentPatch() const {
    return currentPatch;
}

void Database::setCurrentPatch(const String& patch) {
    currentPatch = patch;
}

void Database::changeCurrentPatch(const String& patchName) {
    // Check if the patch exists before changing
    if (searchPatchByName(patchName).patch == patchName) {
        setCurrentPatch(patchName);
    }
}

String Database::getCurrentSelectedPatch() const {
    return currentPatch;
}

Database::PatchStruct Database::getPatchData(const String& patch) {
    String jsonString = preferences.getString(getPatchKey(patch), "{}");
    return fromJson(jsonString);
}

void Database::savePatchData(const PatchStruct& patchData) {
    preferences.putString(getPatchKey(patchData.patch), toJson(patchData));
    persistDatabase();  // Save the database after each update
}

Database::PatchStruct Database::searchPatchByName(const String& patchName) {
    currentIndex = -1;
    for (int i = 0; i < maxPatches; ++i) {
        if (patches[i].patch == patchName) {
            currentIndex = i;
            break;
        }
    }
    return PatchStruct();
}

void Database::persistDatabase() {
    // Save the entire database to Preferences
    DynamicJsonDocument databaseDoc(maxPatches * 1024);
    JsonArray databaseArray = databaseDoc.to<JsonArray>();

    for (int i = 0; i < maxPatches; ++i) {
        JsonArray patchArray = databaseArray.createNestedArray();
        patchArray.add(patches[i].patch);
        // Add other fields ...

        String jsonString;
        serializeJson(patchArray, jsonString);
        preferences.putString(getPatchKey(patches[i].patch), jsonString);
    }
}

String Database::getPatchKey(const String& patch) {
    return "patch_" + patch;
}

String Database::toJson(const Database::PatchStruct& patchData) {
    DynamicJsonDocument doc(1024);
    doc["patch"] = patchData.patch;
    // Add other fields ...

    String jsonString;
    serializeJson(doc, jsonString);
    return jsonString;
}

Database::PatchStruct Database::fromJson(const String& jsonString) {
    DynamicJsonDocument doc(1024);
    deserializeJson(doc, jsonString);

    PatchStruct patchData;
    patchData.patch = doc["patch"];
    // Populate other fields ...

    return patchData;
}

String Database::getPreviousPatch() const {
    int currentIndex = -1;
    for (int i = 0; i < maxPatches; ++i) {
        if (patches[i].patch == currentPatch) {
            currentIndex = i;
            break;
        }
    }

    if (currentIndex > 0) {
        return patches[currentIndex - 1].patch;
    } else {
        return "";
    }
}

Database::PatchStruct Database::openPatch(const String& patchName) {
    currentIndex = -1;
    for (int i = 0; i < maxPatches; ++i) {
        if (patches[i].patch == patchName) {
            currentIndex = i;
            break;
        }
    }

}

String Database::getNextPatch() const {
    int currentIndex = -1;
    for (int i = 0; i < maxPatches; ++i) {
        if (patches[i].patch == currentPatch) {
            currentIndex = i;
            break;
        }
    }

    if (currentIndex < maxPatches - 1) {
        return patches[currentIndex + 1].patch;
    } else {
        return "";
    }
}


String Database::getPreviousPatch() const {
    if (currentIndex > 0) {
        return patches[currentIndex - 1].patch;
    } else {
        return "";
    }
}

String Database::getNextPatch() const {
    if (currentIndex < maxPatches - 1) {
        return patches[currentIndex + 1].patch;
    } else {
        return "";
    }
}

void Database::updatePatchLinks(const String& newPatchName) {
    // Find the index of the new patch
    int newIndex = -1;
    for (int i = 0; i < maxPatches; ++i) {
        if (patches[i].patch == newPatchName) {
            newIndex = i;
            break;
        }
    }
}
