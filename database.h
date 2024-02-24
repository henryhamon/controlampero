
#ifndef DATABASE_H
#define DATABASE_H

#include <EDB.h>

#include "SD.h"
#include "SPI.h"
#include "commons.h"

/*
Convert 2GB to bytes: 2GB = 2 * 1024 * 1024 * 1024 = 2,147,483,648 bytes
Divide the total number of bytes by the size of each Patch object: 2,147,483,648 / 512 = 4,194,304
*/
#define TABLE_SIZE 5000

char *db_name = "/db/controlampero.db";
File dbFile;

void writer(unsigned long address, byte data);
byte reader(unsigned long address);

EDB db(&writer, &reader);

struct Patch
{
    String patch_name;

    int slot_a;
    String slot_a_txt;
    bool slot_a_state;
    int slot_a_type;

    int slot_b;
    String slot_b_txt;
    bool slot_b_state;
    int slot_b_type;

    int slot_c;
    String slot_c_txt;
    bool slot_c_state;
    int slot_c_type;

    int slot_d;
    String slot_d_txt;
    bool slot_d_state;
    int slot_d_type;

    int slot_e;
    String slot_e_txt;
    bool slot_e_state;
    int slot_e_type;

    int slot_f;
    String slot_f_txt;
    bool slot_f_state;
    int slot_f_type;

    int slot_g;
    String slot_g_txt;
    bool slot_g_state;
    int slot_g_type;

    int slot_h;
    String slot_h_txt;
    bool slot_h_state;
    int slot_h_type;
} patch;

void loadPatch(const Patch& currentPatch);

void Populate();
void initDatabase();
void open(const int id);
void openByName(const String name);

#endif

void writer(unsigned long address, byte data)
{
    dbFile.seek(address);
    dbFile.write(data);
    dbFile.flush();
}

byte reader(unsigned long address)
{
    dbFile.seek(address);
    byte b = dbFile.read();
    return b;
}

void initDatabase()
{
    if (!SD.begin(5))
    {
        Serial.println("Card Mount Failed");
        return;
    }
    uint8_t cardType = SD.cardType();

    if (cardType == CARD_NONE)
    {
        Serial.println("No SD card attached");
        return;
    }

    if (!SD.exists("/db"))
    {
        Serial.println("Dir for Db files does not exist, creating...");
        SD.mkdir("/db");
    }


    if (SD.exists(db_name)) {
        dbFile = SD.open(db_name, FILE_WRITE);

        if (!dbFile) {
            dbFile = SD.open(db_name, FILE_WRITE);
        }

        if (dbFile) {
            Serial.print("Openning current table... ");
            EDB_Status result = db.open(0);
            if (result == EDB_OK) {
                Serial.println("DONE");
            } else {
                Serial.println("ERROR");
                Serial.println("Did not find database in the file " + String(db_name));
                Serial.print("Creating new table... ");
                Populate();

                Serial.println("DONE");
                return;
            }
        } else {
            Serial.println("Could not open file " + String(db_name));
            return;
        }
    } else {
        Serial.print("Creating table... ");
        // create table at with starting address 0
        dbFile = SD.open(db_name, FILE_WRITE);
        Populate();
        Serial.println("DONE");
    }
}

void open(const int recno) { 
    Serial.println("load Patch");
    EDB_Status result = db.readRec(recno, EDB_REC patch);
    loadPatch(patch);
}

void openByName(const String name) {
    for (int recno = 1; recno <= db.count(); recno++)
    {
        EDB_Status result = db.readRec(recno, EDB_REC patch);
        if (result == EDB_OK)
        {
            if (patch.patch_name == name) {
                loadPatch(patch);
            }
        }
    }
}

void loadPatch(const Patch& currentPatch) {
    presets[0] = {
        currentPatch.slot_a_txt, 
        currentPatch.slot_a, 
        currentPatch.slot_a_state,
        currentPatch.slot_a_type
    };

    presets[1] = {
        currentPatch.slot_b_txt, 
        currentPatch.slot_b, 
        currentPatch.slot_b_state,
        currentPatch.slot_b_type
    };

    presets[2] = {
        currentPatch.slot_c_txt,
        currentPatch.slot_c,
        currentPatch.slot_c_state,
        currentPatch.slot_c_type
    };

    presets[3] = {
        currentPatch.slot_d_txt,
        currentPatch.slot_d,
        currentPatch.slot_d_state,
        currentPatch.slot_d_type
    };

    presets[4] = {
        currentPatch.slot_e_txt,
        currentPatch.slot_e,
        currentPatch.slot_e_state,
        currentPatch.slot_e_type
    };

    presets[5] = {
        currentPatch.slot_f_txt,
        currentPatch.slot_f,
        currentPatch.slot_f_state,
        currentPatch.slot_f_type
    };

    presets[6] = {
        currentPatch.slot_g_txt,
        currentPatch.slot_g,
        currentPatch.slot_g_state,
        currentPatch.slot_g_type
    };

    presets[7] = {
        currentPatch.slot_h_txt,
        currentPatch.slot_h,
        currentPatch.slot_h_state,
        currentPatch.slot_h_type
    };

    buttonStates[0] = currentPatch.slot_a_state;
    buttonStates[1] = currentPatch.slot_b_state;
    buttonStates[2] = currentPatch.slot_c_state;
    buttonStates[3] = currentPatch.slot_d_state;
    buttonStates[4] = currentPatch.slot_e_state;
    buttonStates[5] = currentPatch.slot_f_state;
    buttonStates[6] = currentPatch.slot_g_state;
    buttonStates[7] = currentPatch.slot_h_state;
}

void Populate() {
    db.create(0, TABLE_SIZE, (unsigned int)sizeof(Patch));

    Patch patches[] = {
        {
            "058-3",
            0, "NOISE G", true, 3,
            1, "COMPRESSOR", true, 3,
            3, "OVERDRIVE", false, 3,
            4, "DISTORT", true, 3,
            5, "FLANGER", true, 3,
            8, "TAPE DLY", true, 3,
            10, "REVERB", true, 3,
            11, "PHASE", true, 3
        },
        {
            "059-1",
            0, "COMPRESSOR", false, 3,
            0, "BOOST", false, 3,
            0, "CRUNCH", true, 3,
            0, "DISTORT", false, 3,
            0, "DELAY 1", true, 3,
            0, "DELAY 2", false, 3,
            0, "REVERB 1", false, 3,
            0, "REVERB 2", false, 3
        }
    };

    for (const auto& patch : patches) {
        db.appendRec(EDB_REC patch);
    }

/*
    Patch patch;
    Patch patch2;

    patch.patch_name = "058-3";

    patch.slot_a = 0;
    patch.slot_a_txt = "NOISE G";
    patch.slot_a_state = true;

    patch.slot_b = 1;
    patch.slot_b_txt = "COMPRESSOR";
    patch.slot_b_state = true;

    patch.slot_c = 3;
    patch.slot_c_txt = "OVERDRIVE";
    patch.slot_c_state = false;

    patch.slot_d = 4;
    patch.slot_d_txt = "DISTORT";
    patch.slot_d_state = true;

    patch.slot_e = 5;
    patch.slot_e_txt = "FLANGER";
    patch.slot_e_state = true;

    patch.slot_f = 8;
    patch.slot_f_txt = "TAPE DLY";
    patch.slot_f_state = true;

    patch.slot_g = 10;
    patch.slot_g_txt = "REVERB";
    patch.slot_g_state = true;

    patch.slot_h = 11;
    patch.slot_h_txt = "PHASE";
    patch.slot_h_state = true;

    db.appendRec(EDB_REC patch);

    patch2.patch_name = "059-1";

    patch2.slot_a = 0;
    patch2.slot_a_txt = "COMPRESSOR";
    patch2.slot_a_state = false;

    patch2.slot_b = 0;
    patch2.slot_b_txt = "BOOST";
    patch2.slot_b_state = false;

    patch2.slot_c = 0;
    patch2.slot_c_txt = "CRUNCH";
    patch2.slot_c_state = true;

    patch2.slot_d = 0;
    patch2.slot_d_txt = "DISTORT";
    patch2.slot_d_state = false;

    patch2.slot_e = 0;
    patch2.slot_e_txt = "DELAY 1";
    patch2.slot_e_state = true;

    patch2.slot_f = 0;
    patch2.slot_f_txt = "DELAY 2";
    patch2.slot_f_state = false;

    patch2.slot_g = 0;
    patch2.slot_g_txt = "REVERB 1";
    patch2.slot_g_state = false;

    patch2.slot_h = 0;
    patch2.slot_h_txt = "REVERB 2";
    patch2.slot_h_state = false;

    db.appendRec(EDB_REC patch2);

*/
}