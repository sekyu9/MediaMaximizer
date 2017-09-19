#include "stdafx.h"
#include "ScentCS.h"

string ScentCS::uri = "urn:mpeg:mpeg-v:01-SI-ScentCS-NS:";

string ScentCS::scentStringArray [] = { "rose", "acacia", "chrysanthemum", "lilac", "mint", "jasmine", "pine_tree", "orange", "grape", "almonds", "amaretto", "apples_green", "apples_red",
			"bacon", "bacon_smokey", "banana", "banana_splits", "basil_herd", "beef", "blackcurrant", "boiled_cabbage", "brandy", "bread", "bubble_gum", "cake_shop", "candy_floss", "caramel_toffee",
			"carrot", "celery", "cherry", "chicken", "coconut", "chocolate_dark", "chocolate_orange", "christmas_apple", "christmas_pudding", "cinnamon", "coffee_chocolate", "coffee_cream", "cola",
			"confectionary", "cookie", "coriander", "crusty_bread", "curry", "fishmarket", "fruit_cake", "fruit_punch_br_fruity_sweets", "garden_mint", "garlic", "gingerbread", "grannies_kitchen",
			"grapefruit", "herbs_mixed", "herring", "honey", "hot_apple_pie", "irish_cream", "jambalaya", "jelly_babies", "kiwi_fruit", "lime_splash", "liquorice", "mango_delight", "melon",
			"mint_chocolate", "mulled_wine", "nutmeg", "onion", "orange_cupcake", "orange_nf", "passion_fruit", "peach_flesh", "pear_drops", "peppermint", "pina_colada", "pineapple", "popcorn",
			"raspberry", "raspberry_ripples", "rhubarb", "rosemary", "rum", "smoked_fish", "spices_mixed", "stir_fry", "strawberry", "sugar_spice_christmas_aroma", "sweet_sherry", "tangerine",
			"tea_leaf", "thai_curry", "toffee_apple", "tomato_plant", "watermelon", "whisky", "wine_oak_cask", "vanilla", "whisky_scotch", "alpine_laundry_powder", "alpine", "amulet", "aquawave",
			"aristocrat", "baby_powder", "beauty_soap", "bergamot", "boiler_room", "bouquet", "brewery", "burning_peat", "burnt_wood", "cannon", "carnation", "caribbean_holiday", "carbolic_soap",
			"cedar_wood", "chamomile", "christmas_berries", "christmas_tree", "christmas_time", "church_incense", "cloisters", "clinic_hospital", "coal_face", "coal_fire", "coal_gas", "cocomango",
			"cuban_cigar_smoke", "cut_grass", "deep_heat", "dentist-clove_oil", "dinosaur", "dirty_linen", "dragons_breath", "dressing_room_football", "Scent of earthy", "eau_de_cologne",
			"eucalyptus", "eau_de_cologne_factory", "farmyard", "factory", "fish_market", "flatulence", "footie_pitch", "forest", "fox", "freesia", "fresh_air", "frosty", "golden_one", "grass_hay",
			"gun_smoke", "havana_cigar", "hawaiian", "heather_bracken", "honeysuckle", "hospital_modern_day", "hyacinth", "incense", "iron_smelting", "jaguar_spray", "japanese_pow", "lavender",
			"leather_cream", "leather_hide", "lemon_eucalyptus_mint", "machine_oil", "mahogany", "man_o_war", "manure_br_methane", "modern_day_hospital", "mountain_heather", "mummy_egyptian",
			"musty", "oak", "old_drifter_ship", "old_inn", "old_river", "old_smithy", "out_at_sea", "ozone", "peat", "pencil_wood_shavings", "peony", "phosgene_gas", "pine", "pineapple_plantation",
			"pine_heather_peat", "pit_ponies", "polish-wax", "pot-pourri", "riverbank", "river_tropics", "rope_tar", "rosewood", "rubbish_acrid", "sandalwood", "sandalwood_basil", "sea_breeze",
			"sea_shore", "sheba", "ships_cannon", "snowdrop", "sports_changing_room", "stables_horses", "stars_dressing_room", "steam_oil_ships", "steam_oil_trains", "street_1930s", "street_bomb",
			"sun_sand_coconut", "swamp", "sweaty_feet", "sweet_peas", "tobacco_leaf", "train_smoke", "trophy_room", "tropical", "tropical_rain_forest", "unisex_perfume", "urine", "usa_swamp",
			"victorian_lavender", "violets", "volcano", "vomit", "wallflower", "washday", "wild_stag", "wine_cask-oak", "wisteria", "woodsmoke", "ylang_jasmin_myrrh", "yuletide", "african_rain",
			"allegria", "amber", "apple_green", "asafoetida", "autumn_fields", "autumn_harvest", "balsam_fir", "balsam_fir_needle", "barnyard", "beer", "benzoin", "birch_tar", "birthday_cake",
			"blueberry_cobbler", "bouquet_of_roses", "buchu", "burning_rubber", "cactus_flower", "cade", "campfire", "campfire_smoke", "camphor", "caribbean_night", "cedar", "champagne_strawberries",
			"chanel_no5_type", "chocolate", "christmas_cookies", "clean_cotton", "cotton_candy", "creme_brule", "cypress_grove", "dumpster", "dung", "easter_lillies", "egg_nog_2", "eucalyptus_dives",
			"evergreen", "exhaust", "fish", "forest_rain", "forget-me-not", "frangipani", "french_fries", "fresh_bread", "fresh_cut_grass", "fresh_laundry", "frying_bacon", "fudge_brownie",
			"gardenia", "grandmas_attic", "halloween_greasepaint", "hawaian_treat", "indian_summer", "jet_fuel", "juniper_berry", "leather", "lotus", "mango_mandarin", "maple_syrup", "mildew",
			"mother_earth", "musk", "new_mown_grass_2", "new_mown_grass_3", "oak_moss", "open_fireplace", "palmarosa", "pancakes_maple_syrup", "patchouli", "pecan_pie", "rain_forest",
			"rich_potting_soil", "roasted_chicken", "sage_dalmatian", "seaweed", "spanish_moss", "spring_bouquet", "suntan", "thyme_borneol", "tomato_vine", "tuberose", "violet", "warming_ginger",
			"ylang_ylang" };

string ScentCS::scentBinaryArray [] = { "000000000", "000000001", "000000010", "000000011", "000000100", "000000101", "000000110", "000000111", "000001000", "000001001", "000001010", "000001011",
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
			"100110010", "100110011", "100110100", "100110101", "100110110", "100110111", "100111000", "100111001", "100111010", "100111011", "100111100", "100111101", "100111110", "100111111",
			"101000000" };


string ScentCS::convertBinaryToString(string scentBinary)
{
	string retValue;

	for (int i = 0; i < SCENT_CS_ARRAY_SIZE; i++) {
		if (scentBinary.compare(scentBinaryArray[i]) == 0) {
			//retValue = uri + scentStringArray[i];
			retValue = scentStringArray[i].append(uri);
			break;
		}
	}

	return retValue;

}

string ScentCS::convertStringToBinary(string scentString)
{
	string retValue;

	if (scentString.compare("") == 0)
		return NULL;

	if (scentString.find(uri) != -1)
	{
		// remove uri from colorString
		scentString = scentString.substr(uri.size(), scentString.size() - uri.size());
	}

	for (int i = 0; i < SCENT_CS_ARRAY_SIZE; i++) {
		if (scentString.compare(scentStringArray[i]) == 0 ) {
			retValue = scentBinaryArray[i];
			break;
		}
	}

	return retValue;
}