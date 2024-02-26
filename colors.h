#ifndef COLORS_H
#define COLORS_H

// https://www.rapidtables.com/web/color/RGB_Color.html

uint32_t color(uint8_t r, uint8_t g, uint8_t b);
uint32_t maroon();
uint32_t dark_red();
uint32_t brown();
uint32_t firebrick();
uint32_t crimson();
uint32_t red();
uint32_t tomato();
uint32_t coral();
uint32_t indian_red();
uint32_t light_coral();
uint32_t dark_salmon();
uint32_t salmon();
uint32_t light_salmon();
uint32_t orange_red();
uint32_t dark_orange();
uint32_t orange();
uint32_t gold();
uint32_t dark_golden_rod();
uint32_t golden_rod();
uint32_t pale_golden_rod();
uint32_t dark_khaki();
uint32_t khaki();
uint32_t olive();
uint32_t yellow();
uint32_t yellow_green();
uint32_t dark_olive_green();
uint32_t olive_drab();
uint32_t lawn_green();
uint32_t chartreuse();
uint32_t green_yellow();
uint32_t dark_green();
uint32_t green();
uint32_t forest_green();
uint32_t lime();
uint32_t lime_green();
uint32_t light_green();
uint32_t pale_green();
uint32_t dark_sea_green();
uint32_t medium_spring_green();
uint32_t spring_green();
uint32_t sea_green();
uint32_t medium_aqua_marine();
uint32_t medium_sea_green();
uint32_t light_sea_green();
uint32_t dark_slate_gray();
uint32_t teal();
uint32_t dark_cyan();
uint32_t aqua();
uint32_t cyan();
uint32_t light_cyan();
uint32_t dark_turquoise();
uint32_t turquoise();
uint32_t medium_turquoise();
uint32_t pale_turquoise();
uint32_t aqua_marine();
uint32_t powder_blue();
uint32_t cadet_blue();
uint32_t steel_blue();
uint32_t corn_flower_blue();
uint32_t deep_sky_blue();
uint32_t dodger_blue();
uint32_t light_blue();
uint32_t sky_blue();
uint32_t light_sky_blue();
uint32_t midnight_blue();
uint32_t navy();
uint32_t dark_blue();
uint32_t medium_blue();
uint32_t blue();
uint32_t royal_blue();
uint32_t blue_violet();
uint32_t indigo();
uint32_t dark_slate_blue();
uint32_t slate_blue();
uint32_t medium_slate_blue();
uint32_t medium_purple();
uint32_t dark_magenta();
uint32_t dark_violet();
uint32_t dark_orchid();
uint32_t medium_orchid();
uint32_t purple();
uint32_t thistle();
uint32_t plum();
uint32_t violet();
uint32_t magenta();
uint32_t orchid();
uint32_t medium_violet_red();
uint32_t pale_violet_red();
uint32_t deep_pink();
uint32_t hot_pink();
uint32_t light_pink();
uint32_t pink();
uint32_t antique_white();
uint32_t beige();
uint32_t bisque();
uint32_t blanched_almond();
uint32_t wheat();
uint32_t corn_silk();
uint32_t lemon_chiffon();
uint32_t light_golden_rod_yellow();
uint32_t light_yellow();
uint32_t saddle_brown();
uint32_t sienna();
uint32_t chocolate();
uint32_t peru();
uint32_t sandy_brown();
uint32_t burly_wood();
uint32_t tan();
uint32_t rosy_brown();
uint32_t moccasin();
uint32_t navajo_white();
uint32_t peach_puff();
uint32_t misty_rose();
uint32_t lavender_blush();
uint32_t linen();
uint32_t old_lace();
uint32_t papaya_whip();
uint32_t sea_shell();
uint32_t mint_cream();
uint32_t slate_gray();
uint32_t light_slate_gray();
uint32_t light_steel_blue();
uint32_t lavender();
uint32_t floral_white();
uint32_t alice_blue();
uint32_t ghost_white();
uint32_t honeydew();
uint32_t ivory();
uint32_t azure();
uint32_t snow();
uint32_t black();
uint32_t dim_gray();
uint32_t gray();
uint32_t dark_gray();
uint32_t silver();
uint32_t light_gray();
uint32_t gainsboro();
uint32_t white_smoke();
uint32_t white();

#endif

uint32_t color(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t packed = 0;
    packed = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
    return packed;
}

// maroon
uint32_t maroon()
{
    return color(128, 0, 0);
}

// dark red
uint32_t dark_red()
{
    return color(139, 0, 0);
}

// brown
uint32_t brown()
{
    return color(165, 42, 42);
}

// firebrick
uint32_t firebrick()
{
    return color(178, 34, 34);
}

// crimson
uint32_t crimson()
{
    return color(220, 20, 60);
}

// red
uint32_t red()
{
    return color(255, 0, 0);
}

// tomato
uint32_t tomato()
{
    return color(255, 99, 71);
}

// coral
uint32_t coral()
{
    return color(255, 127, 80);
}

// indian red
uint32_t indian_red()
{
    return color(205, 92, 92);
}

// light coral
uint32_t light_coral()
{
    return color(240, 128, 128);
}

// dark salmon
uint32_t dark_salmon()
{
    return color(233, 150, 122);
}

// salmon
uint32_t salmon()
{
    return color(250, 128, 114);
}

// light salmon
uint32_t light_salmon()
{
    return color(255, 160, 122);
}

// orange red
uint32_t orange_red()
{
    return color(255, 69, 0);
}

// dark orange
uint32_t dark_orange()
{
    return color(255, 140, 0);
}

// orange
uint32_t orange()
{
    return color(255, 165, 0);
}

// gold
uint32_t gold()
{
    return color(255, 215, 0);
}

// dark golden rod
uint32_t dark_golden_rod()
{
    return color(184, 134, 11);
}

// golden rod
uint32_t golden_rod()
{
    return color(218, 165, 32);
}

// pale golden rod
uint32_t pale_golden_rod()
{
    return color(238, 232, 170);
}

// dark khaki
uint32_t dark_khaki()
{
    return color(189, 183, 107);
}

// khaki
uint32_t khaki()
{
    return color(240, 230, 140);
}

// olive
uint32_t olive()
{
    return color(128, 128, 0);
}

// yellow
uint32_t yellow()
{
    return color(255, 255, 0);
}

// yellow green
uint32_t yellow_green()
{
    return color(154, 205, 50);
}

// dark olive green
uint32_t dark_olive_green()
{
    return color(85, 107, 47);
}

// olive drab
uint32_t olive_drab()
{
    return color(107, 142, 35);
}

// lawn green
uint32_t lawn_green()
{
    return color(124, 252, 0);
}

// chartreuse
uint32_t chartreuse()
{
    return color(127, 255, 0);
}

// green yellow
uint32_t green_yellow()
{
    return color(173, 255, 47);
}

// dark green
uint32_t dark_green()
{
    return color(0, 100, 0);
}

// green
uint32_t green()
{
    return color(0, 128, 0);
}

// forest green
uint32_t forest_green()
{
    return color(34, 139, 34);
}

// lime
uint32_t lime()
{
    return color(0, 255, 0);
}

// lime green
uint32_t lime_green()
{
    return color(50, 205, 50);
}

// light green
uint32_t light_green()
{
    return color(144, 238, 144);
}

// pale green
uint32_t pale_green()
{
    return color(152, 251, 152);
}

// dark sea green
uint32_t dark_sea_green()
{
    return color(143, 188, 143);
}

// medium spring green
uint32_t medium_spring_green()
{
    return color(0, 250, 154);
}

// spring green
uint32_t spring_green()
{
    return color(0, 255, 127);
}

// sea green
uint32_t sea_green()
{
    return color(46, 139, 87);
}

// medium aqua marine
uint32_t medium_aqua_marine()
{
    return color(102, 205, 170);
}

// medium sea green
uint32_t medium_sea_green()
{
    return color(60, 179, 113);
}

// light sea green
uint32_t light_sea_green()
{
    return color(32, 178, 170);
}

// dark slate gray
uint32_t dark_slate_gray()
{
    return color(47, 79, 79);
}

// teal
uint32_t teal()
{
    return color(0, 128, 128);
}

// dark cyan
uint32_t dark_cyan()
{
    return color(0, 139, 139);
}

// aqua
uint32_t aqua()
{
    return color(0, 255, 255);
}

// cyan
uint32_t cyan()
{
    return color(0, 255, 255);
}

// light cyan
uint32_t light_cyan()
{
    return color(224, 255, 255);
}

// dark turquoise
uint32_t dark_turquoise()
{
    return color(0, 206, 209);
}

// turquoise
uint32_t turquoise()
{
    return color(64, 224, 208);
}

// medium turquoise
uint32_t medium_turquoise()
{
    return color(72, 209, 204);
}

// pale turquoise
uint32_t pale_turquoise()
{
    return color(175, 238, 238);
}

// aqua marine
uint32_t aqua_marine()
{
    return color(127, 255, 212);
}

// powder blue
uint32_t powder_blue()
{
    return color(176, 224, 230);
}

// cadet blue
uint32_t cadet_blue()
{
    return color(95, 158, 160);
}

// steel blue
uint32_t steel_blue()
{
    return color(70, 130, 180);
}

// corn flower blue
uint32_t corn_flower_blue()
{
    return color(100, 149, 237);
}

// deep sky blue
uint32_t deep_sky_blue()
{
    return color(0, 191, 255);
}

// dodger blue
uint32_t dodger_blue()
{
    return color(30, 144, 255);
}

// light blue
uint32_t light_blue()
{
    return color(173, 216, 230);
}

// sky blue
uint32_t sky_blue()
{
    return color(135, 206, 235);
}

// light sky blue
uint32_t light_sky_blue()
{
    return color(135, 206, 250);
}

// midnight blue
uint32_t midnight_blue()
{
    return color(25, 25, 112);
}

// navy
uint32_t navy()
{
    return color(0, 0, 128);
}

// dark blue
uint32_t dark_blue()
{
    return color(0, 0, 139);
}

// medium blue
uint32_t medium_blue()
{
    return color(0, 0, 205);
}

// blue
uint32_t blue()
{
    return color(0, 0, 255);
}

// royal blue
uint32_t royal_blue()
{
    return color(65, 105, 225);
}

// blue violet
uint32_t blue_violet()
{
    return color(138, 43, 226);
}

// indigo
uint32_t indigo()
{
    return color(75, 0, 130);
}

// dark slate blue
uint32_t dark_slate_blue()
{
    return color(72, 61, 139);
}

// slate blue
uint32_t slate_blue()
{
    return color(106, 90, 205);
}

// medium slate blue
uint32_t medium_slate_blue()
{
    return color(123, 104, 238);
}

// medium purple
uint32_t medium_purple()
{
    return color(147, 112, 219);
}

// dark magenta
uint32_t dark_magenta()
{
    return color(139, 0, 139);
}

// dark violet
uint32_t dark_violet()
{
    return color(148, 0, 211);
}

// dark orchid
uint32_t dark_orchid()
{
    return color(153, 50, 204);
}

// medium orchid
uint32_t medium_orchid()
{
    return color(186, 85, 211);
}

// purple
uint32_t purple()
{
    return color(128, 0, 128);
}

// thistle
uint32_t thistle()
{
    return color(216, 191, 216);
}

// plum
uint32_t plum()
{
    return color(221, 160, 221);
}

// violet
uint32_t violet()
{
    return color(238, 130, 238);
}

// magenta
uint32_t magenta()
{
    return color(255, 0, 255);
}

// orchid
uint32_t orchid()
{
    return color(218, 112, 214);
}

// medium violet red
uint32_t medium_violet_red()
{
    return color(199, 21, 133);
}

// pale violet red
uint32_t pale_violet_red()
{
    return color(219, 112, 147);
}

// deep pink
uint32_t deep_pink()
{
    return color(255, 20, 147);
}

// hot pink
uint32_t hot_pink()
{
    return color(255, 105, 180);
}

// light pink
uint32_t light_pink()
{
    return color(255, 182, 193);
}

// pink
uint32_t pink()
{
    return color(255, 192, 203);
}

// antique white
uint32_t antique_white()
{
    return color(250, 235, 215);
}

// beige
uint32_t beige()
{
    return color(245, 245, 220);
}

// bisque
uint32_t bisque()
{
    return color(255, 228, 196);
}

// blanched almond
uint32_t blanched_almond()
{
    return color(255, 235, 205);
}

// wheat
uint32_t wheat()
{
    return color(245, 222, 179);
}

// corn silk
uint32_t corn_silk()
{
    return color(255, 248, 220);
}

// lemon chiffon
uint32_t lemon_chiffon()
{
    return color(255, 250, 205);
}

// light golden rod yellow
uint32_t light_golden_rod_yellow()
{
    return color(250, 250, 210);
}

// light yellow
uint32_t light_yellow()
{
    return color(255, 255, 224);
}

// saddle brown
uint32_t saddle_brown()
{
    return color(139, 69, 19);
}

// sienna
uint32_t sienna()
{
    return color(160, 82, 45);
}

// chocolate
uint32_t chocolate()
{
    return color(210, 105, 30);
}

// peru
uint32_t peru()
{
    return color(205, 133, 63);
}

// sandy brown
uint32_t sandy_brown()
{
    return color(244, 164, 96);
}

// burly wood
uint32_t burly_wood()
{
    return color(222, 184, 135);
}

// tan
uint32_t tan()
{
    return color(210, 180, 140);
}

// rosy brown
uint32_t rosy_brown()
{
    return color(188, 143, 143);
}

// moccasin
uint32_t moccasin()
{
    return color(255, 228, 181);
}

// navajo white
uint32_t navajo_white()
{
    return color(255, 222, 173);
}

// peach puff
uint32_t peach_puff()
{
    return color(255, 218, 185);
}

// misty rose
uint32_t misty_rose()
{
    return color(255, 228, 225);
}

// lavender blush
uint32_t lavender_blush()
{
    return color(255, 240, 245);
}

// linen
uint32_t linen()
{
    return color(250, 240, 230);
}

// old lace
uint32_t old_lace()
{
    return color(253, 245, 230);
}

// papaya whip
uint32_t papaya_whip()
{
    return color(255, 239, 213);
}

// sea shell
uint32_t sea_shell()
{
    return color(255, 245, 238);
}

// mint cream
uint32_t mint_cream()
{
    return color(245, 255, 250);
}

// slate gray
uint32_t slate_gray()
{
    return color(112, 128, 144);
}

// light slate gray
uint32_t light_slate_gray()
{
    return color(119, 136, 153);
}

// light steel blue
uint32_t light_steel_blue()
{
    return color(176, 196, 222);
}

// lavender
uint32_t lavender()
{
    return color(230, 230, 250);
}

// floral white
uint32_t floral_white()
{
    return color(255, 250, 240);
}

// alice blue
uint32_t alice_blue()
{
    return color(240, 248, 255);
}

// ghost white
uint32_t ghost_white()
{
    return color(248, 248, 255);
}

// honeydew
uint32_t honeydew()
{
    return color(240, 255, 240);
}

// ivory
uint32_t ivory()
{
    return color(255, 255, 240);
}

// azure
uint32_t azure()
{
    return color(240, 255, 255);
}

// snow
uint32_t snow()
{
    return color(255, 250, 250);
}

// black
uint32_t black()
{
    return color(0, 0, 0);
}

// dim gray
uint32_t dim_gray()
{
    return color(105, 105, 105);
}

// gray
uint32_t gray()
{
    return color(128, 128, 128);
}

// dark gray
uint32_t dark_gray()
{
    return color(169, 169, 169);
}

// silver
uint32_t silver()
{
    return color(192, 192, 192);
}

// light gray
uint32_t light_gray()
{
    return color(211, 211, 211);
}

// gainsboro
uint32_t gainsboro()
{
    return color(220, 220, 220);
}

// white smoke
uint32_t white_smoke()
{
    return color(245, 245, 245);
}

// white
uint32_t white()
{
    return color(255, 255, 255);
}
