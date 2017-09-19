#include "stdafx.h"
#include "ColorCS.h"
#include "ColorType.h"

string ColorCS::uri = "urn:mpeg:mpeg-v:01-SI-ColorCS-NS:";

string ColorCS::colorStringArray [] = { 
	"alice_blue", "alizarin", "amaranth", "amaranth_pink", "amber", "amethyst", "apricot", "aqua", "aquamarine", "army_green", "asparagus", "atomic_tangerine",
	"auburn", "azure_color_wheel", "azure_web", "baby_blue", "beige", "bistre", "black", "blue", "blue_pigment", "blue_ryb", "blue-green", "blue-violet", "bondi_blue", "brass",
	"bright_green", "bright_pink", "bright_turquoise", "brilliant_rose", "brink_pink", "bronze", "brown", "buff", "burgundy", "burnt_orange", "burnt_sienna", "burnt_umber",
	"camouflage_green", "caput_mortuum", "cardinal", "carmine", "carmine_pink", "carnation_pink", "carolina_blue", "carrot_orange", "celadon", "cerise", "cerise_pink", "cerulean",
	"cerulean_blue", "champagne", "charcoal", "chartreuse_traditional", "chartreuse_web", "cherry_blossom_pink", "chestnut", "chocolate", "cinnabar", "cinnamon", "cobalt", "columbia_blue",
	"copper", "copper_rose", "coral", "coral_pink", "coral_red", "corn", "cornflower_blue", "cosmic_latte", "cream", "crimson", "cyan", "cyan_process", "dark_blue", "dark_brown",
	"dark_cerulean", "dark_chestnut", "dark_coral", "dark_goldenrod", "dark_green", "dark_khaki", "dark_magenta", "dark_pastel_green", "dark_pink", "dark_scarlet", "dark_salmon",
	"dark_slate_gray", "dark_spring_green", "dark_tan", "dark_turquoise", "dark_violet", "deep_carmine_pink", "deep_cerise", "deep_chestnut", "deep_fuchsia", "deep_lilac", "deep_magenta",
	"deep_peach", "deep_pink", "denim", "dodger_blue", "ecru", "egyptian_blue", "electric_blue", "electric_green_x11_green", "elctric_indigo", "electric_lime", "electric_purple",
	"emerald", "eggplant", "falu_red", "fern_green", "firebrick", "flax", "forest_green", "french_rose", "fuchsia", "fuchsia_pink", "gamboge", "gold_metallic", "gold_web_golden",
	"golden_brown", "golden_yellow", "goldenrod", "grey-asparagus", "green", "green_html/css_green", "green_pigment", "green_ryb", "green_yellow", "grey", "han_purple",
	"harlequin", "heliotrope", "Hollywood_cerise", "hot_magenta", "hot_pink", "indigo_dye", "indigo_web", "international_klein_blue", "international_orange", "Islamic_green", "ivory", "jade",
	"kelly_green", "khaki", "khaki_x11_light_khaki", "lavender_floral", "lavender_web", "lavender_blue", "lavender_blush", "lavender_grey", "lavender_magenta", "lavender_pink",
	"lavender_purple", "lavender_rose", "lawn_green", "lemon", "lemon_chiffon", "light_blue", "light_pink", "lilac", "lime_color_wheel", "lime_web_x11_green", "lime_green", "linen",
	"magenta", "magenta_dye", "magenta_process", "magic_mint", "magnolia", "malachite", "maroon_html/css", "marron_x11", "maya_blue", "mauve", "mauve_taupe", "medium_blue", "medium_carmine",
	"medium_lavender_magenta", "medum_purple", "medium_spring_green", "midnight_blue", "midnight_green_eagle_green", "mint_green", "misty_rose", "moss_green", "mountbatten_pink", "mustard",
	"myrtle", "navajo_white", "navy_blue", "ochre", "office_green", "old_gold", "old_lace", "old_lavender", "old_rose", "olive", "olive_drab", "olivine", "orange_color_wheel", "orange_ryb",
	"orange_web", "orange_peel", "orange-red", "orchid", "pale_blue", "pale_brown", "pale_carmine", "pale_chestnut", "pale_cornflower_blue", "pale_magenta", "pale_pink", "pale_red-violet",
	"papaya_whip", "pastel_green", "pastel_pink", "peach", "peach-orange", "peach-yellow", "pear", "periwinkle", "persian_blue", "persian_green", "persian_indigo", "persian_orange",
	"persian_red", "persian_pink", "persian_rose", "persimmon", "pine_green", "pink", "pink-orange", "platinum", "plum_web", "powder_blue_web", "puce", "prussian_blue", "psychedelic_purple",
	"pumpkin", "purple_html/css", "purple_x11", "purple_taupe", "raw_umber", "razzmatazz", "red", "red_pigment", "red_ryb", "red-violet", "rich_carmine", "robin_egg_blue", "rose",
	"rose_madder", "rose_taupe", "royal_blue", "royal_purple", "ruby", "russet", "rust", "safety_orange_blaze_orange", "saffron", "salmon", "sandy_brown", "sangria", "sapphire", "scarlet",
	"school_bus_yellow", "sea_green", "seashell", "selective_yellow", "sepia", "shamrock_green", "shocking_pink", "silver", "sky_blue", "slate_grey", "smalt_dark_powder_blue", "spring_bud",
	"spring_green", "steel_blue", "tan", "tangerine", "tangerine_yellow", "taupe", "tea_green", "tea_rose_orange", "tea_rose_rose", "teal", "tenne_tawny", "terra_cotta", "thistle", "tomato",
	"turquoise", "tyrian_purple", "ultramarine", "ultra_pink", "united_nation_blue", "vegas_gold", "vermilion", "violet", "violet_web", "violet_ryb", "viridian", "wheat", "white", "wisteria",
	"yellow", "yellow_process", "yellow_ryb", "yellow_green" 
};

string ColorCS::colorBinaryArray [] = { "000000000", "000000001", "000000010", "000000011", "000000100", "000000101", "000000110", "000000111", "000001000", "000001001", "000001010", "000001011",
			"000001100", "000001101", "000001110", "000001111", "000010000", "000010001", "000010010", "000010011", "000010100", "000010101", "000010110", "000010111", "000011000", "000011001",
			"000011010", "000011011", "000011100", "000011101", "000011110", "000011111", "000100000", "000100001", "000100010", "000100011", "000100100", "000100101", "000100110", "000100111",
			"000101000", "000101001", "000101010", "000101011", "000101100", "000101101", "000101110", "000101111", "000110000", "000110001", "000110010", "000110011", "000110100", "000110101",
			"000110110", "000110111", "000111000", "000111001", "000111010", "000111011", "000111100", "000111101", "000111110", "000111111", "001000000", "001000001", "001000010", "001000011",
			"001000100", "001000101", "001000110", "001000111", "001001000", "001001001", "001001010", "001001011", "001001100", "001001101", "001001110", "001001111", "001010000", "001010001",
			"001010010", "001010011", "001010100", "001010101", "001010110", "001010111", "001011000", "001011001", "001011010", "001011011", "001011100", "001011101", "001011110", "001011111",
			"001100000", "001100001", "001100010", "001100011", "001100100", "001100101", "001100110", "001100111", "001101000", "001101001", "001101010", "001101011", "001101100", "001101101",
			"001101110", "001101111", "001110000", "001110001", "001110010", "001110011", "001110100", "001110101", "001110110", "001110111", "001111000", "001111001", "001111010", "001111011",
			"001111100", "001111101", "001111110", "001111111", "010000000", "010000001", "010000010", "010000011", "010000100", "010000101", "010000110", "010000111", "010001000", "010001001",
			"010001010", "010001011", "010001100", "010001101", "010001110", "010001111", "010010000", "010010001", "010010010", "010010011", "010010100", "010010101", "010010110", "010010111",
			"010011000", "010011001", "010011010", "010011011", "010011100", "010011101", "010011110", "010011111", "010100000", "010100001", "010100010", "010100011", "010100100", "010100101",
			"010100110", "010100111", "010101000", "010101001", "010101010", "010101011", "010101100", "010101101", "010101110", "010101111", "010110000", "010110001", "010110010", "010110011",
			"010110100", "010110101", "010110110", "010110111", "010111000", "010111001", "010111010", "010111011", "010111100", "010111101", "010111110", "010111111", "011000000", "011000001",
			"011000010", "011000011", "011000100", "011000101", "011000110", "011000111", "011001000", "011001001", "011001010", "011001011", "011001100", "011001101", "011001110", "011001111",
			"011010000", "011010001", "011010010", "011010011", "011010100", "011010101", "011010110", "011010111", "011011000", "011011001", "011011010", "011011011", "011011100", "011011101",
			"011011110", "011011111", "011100000", "011100001", "011100010", "011100011", "011100100", "011100101", "011100110", "011100111", "011101000", "011101001", "011101010", "011101011",
			"011101100", "011101101", "011101110", "011101111", "011110000", "011110001", "011110010", "011110011", "011110100", "011110101", "011110110", "011110111", "011111000", "011111001",
			"011111010", "011111011", "011111100", "011111101", "011111110", "011111111", "100000000", "100000001", "100000010", "100000011", "100000100", "100000101", "100000110", "100000111",
			"100001000", "100001001", "100001010", "100001011", "100001100", "100001101", "100001110", "100001111", "100010000", "100010001", "100010010", "100010011", "100010100", "100010101",
			"100010110", "100010111", "100011000", "100011001", "100011010", "100011011", "100011100", "100011101", "100011110", "100011111", "100100000", "100100001", "100100010", "100100011",
			"100100100", "100100101", "100100110", "100100111", "100101000", "100101001", "100101010", "100101011", "100101100", "100101101", "100101110", "100101111", "100110000", "100110001",
			"100110010", "100110011", "100110100", "100110101", "100110110", "100110111" };

string ColorCS::colorRGBArray [] = {
	"240:248:255", "227:38:54", "229:43:80", "241:156:187", "255:191:0", "153:102:204", "251:206:177", "0:255:255", "127:255:212", "75:83:32", "123:160:91", "255:153:102", "111:53:26", "0:127:255", "240:255:255", "224:255:255", "245:245:220", "61:43:31", "0:0:0", "0:0:255", "51:51:153", "2:71:254", "0:223:223", "138:43:226", "0:149:182", "181:166:66", "102:255:0", "255:0:127", "8:232:222", "255:85:163", "251:96:127", "205:127:50", "150:75:0", "240:220:130", "128:0:32", "204:85:0", "233:116:81", "138:51:36", "120:134:107", "89:39:32", "196:30:58", "150:0:24", "235:76:66", "255:166:201", "156:186:227", "237:145:33", "172:225:175", "222:49:99", "236:59:131", "0:123:167", "42:82:190", "247:231:206", "70:70:70", "223:255:0", "127:255:0", "255:183:197", "205:92:92", "123:63:0", "227:66:52", "210:105:30", "0:71:171", "155:221:255", "184:115:51", "153:102:102", "255:127:80", "248:131:121", "255:64:64", "251:236:93", "100:149:237", "255:248:231", "255:253:208", "220:20:60", "0:255:255", "0:180:247", "0:0:139", "101:67:33", "8:69:126", "152:105:96", "205:91:69", "184:134:11", "1:50:32", "189:183:107", "139:0:139", "3:192:60", "231:84:128", "86:3:25", "233:150:122", "47:79:79", "23:114:69", "145:129:81", "0:206:209", "148:0:211", "239:48:56", "218:50:135", "185:78:72", "193:84:193", "153:85:187", "204:0:204", "255:203:164", "255:20:147", "21:96:189", "30:144:255", "194:178:128", "16:52:166", "125:249:255", "0:255:0", "102:0:255", "204:255:0", "191:0:255", "80:200:120", "97:64:81", "128:24:24", "79:121:66", "178:34:34", "238:220:130", "34:139:34", "246:74:138", "255:0:255", "255:119:255", "228:155:15", "212:175:55", "255:215:0", "153:101:21", "255:223:0", "218:165:32", "70:89:69", "0:255:0", "0:128:0", "0:165:80", "102:176:50", "173:255:47", "128:128:128", "82:24:250", "63:255:0", "223:115:255", "244:0:161", "255:0:204", "255:105:180", "0:65:106", "75:0:130", "0:47:167", "255:79:0", "0:153:0", "255:255:240", "0:168:107", "76:187:23", "195:176:145", "240:230:140", "181:126:220", "230:230:250", "204:204:255", "255:240:245", "196:195:221", "238:130:238", "251:174:210", "150:120:182", "251:160:227", "124:252:0", "253:233:16", "255:250:205", "173:216:230", "255:182:193", "200:162:200", "191:255:0", "0:255:0", "50:205:50", "250:240:230", "255:0:255", "202:31:23", "255:0:144", "170:240:209", "248:244:255", "11:218:81", "128:0:0", "176:48:96", "115:194:251", "224:176:255", "145:95:109", "0:0:205", "175:64:53", "204:153:204", "147:112:219", "0:250:154", "25:25:112", "0:73:83", "152:255:152", "255:228:225", "173:223:173", "153:122:141", "255:219:88", "33:66:30", "255:222:173", "0:0:128", "204:119:34", "0:128:0", "207:181:59", "253:245:230", "121:104:120", "192:128:129", "128:128:0", "107:142:35", "154:185:115", "255:127:0", "251:153:2", "255:165:0", "255:160:0", "255:69:0", "218:112:214", "175:238:238", "152:118:84", "175:64:53", "221:173:175", "171:205:239", "249:132:229", "250:218:221", "219:112:147", "255:239:213", "119:221:119", "255:209:220", "255:229:180", "255:204:153", "250:223:173", "209:226:49", "204:204:255", "28:57:187", "0:166:147", "50:18:122", "217:144:88", "204:51:51", "247:127:190", "254:40:162", "236:88:0", "1:121:111", "255:192:203", "255:153:102", "229:228:226", "204:153:204", "176:224:230", "204:136:153", "0:49:83", "221:0:255", "255:117:24", "128:0:128", "160:92:240", "80:64:77", "115:74:18", "227:11:92", "255:0:0", "237:28:36", "254:39:18", "199:21:133", "215:0:64", "0:204:204", "255:0:127", "227:38:54", "144:93:93", "65:105:225", "107:63:160", "224:17:95", "128:70:27", "183:65:14", "255:102:0", "244:196:48", "255:140:105", "244:164:96", "146:0:10", "8:37:103", "255:36:0", "255:216:0", "46:139:87", "255:245:238", "255:186:0", "112:66:20", "0:158:96", "252:15:192", "192:192:192", "135:206:235", "112:128:144", "0:51:153", "167:252:0", "0:255:127", "70:130:180", "210:180:140", "242:133:0", "255:204:0", "72:60:50", "208:240:192", "248:131:194", "244:194:194", "0:128:128", "205:87:0", "226:114:91", "216:191:216", "255:99:71", "48:213:200", "102:2:60", "18:10:143", "255:111:255", "91:146:229", "197:179:88", "227:66:51", "139:0:255", "238:130:238", "2:71:54", "64:130:109", "245:222:179", "255:255:255", "201:160:220", "255:255:0", "255:239:0", "254:254:51", "154:205:50"
};

string ColorCS::convertBinaryToString(string colorBinary)
{
	string retValue;

	for (int i = 0; i < COLOR_CS_ARRAY_SIZE; i++) {
		if (colorBinary.compare(colorBinaryArray[i]) == 0) {
			retValue = colorStringArray[i].append(uri);
			break;
		}
	}
	return retValue;

}

string ColorCS::convertStringToBinary(string colorString)
{
	string retValue;

	if (colorString.compare("") == 0)
		return NULL;

	if (colorString.find(uri) != -1)
	{
		// remove uri from colorString
		colorString = colorString.substr(uri.size(), colorString.size() - uri.size());
	}

	for (int i = 0; i < COLOR_CS_ARRAY_SIZE; i++) {
		if (colorString.compare(colorStringArray[i]) == 0) {
			retValue = colorBinaryArray[i];
			break;
		}
	}

	return retValue;
}

string ColorCS::convertColorToRGB(string colorName)
{
	int index = 0;

	for(int i = 0; i < COLOR_CS_ARRAY_SIZE; i++)
	{
		if(colorName.compare(colorStringArray[i]) == 0)
		{
			index = i;
			break;
		}
	}

	return colorRGBArray[index];
}

//void ColorCS::convertToAmbxRGB(string colorRGBType)
//{
//	Ambx *ambx = new Ambx;
//	
//	int i;
//	int checkCount=0;
//	
//	string rgbBuffer="";
//
//	//int intValue = atoi(colorRGBType.c_str());
//
//	for(i = 0;i < colorRGBType.length(); i++)
//	{
//		if(colorRGBType.at(i) != ':')
//		{
//			rgbBuffer+=colorRGBType.at(i);
//		} 
//		else
//		{
//			switch(checkCount)
//			{
//			case 0:
//				ambx->setAmBX_R(((float)atoi(rgbBuffer.c_str()))/255);
//				break;
//			case 1:
//				ambx->setAmBX_G(((float)atoi(rgbBuffer.c_str()))/255);
//				break;
//			case 2:
//				ambx->setAmBX_B(((float)atoi(rgbBuffer.c_str()))/255);
//				break;
//			}
//
//			rgbBuffer = "";
//			checkCount++;
//		}
//	}
//}