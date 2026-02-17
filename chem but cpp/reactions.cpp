#include <iostream>
#include <string>

using namespace std;


void check(string inp, string ans) {
	if (inp == ans) {cout << "\nYerp. " << flush;} else {cout << "\nNarp (it's " << ans << ") " << flush;}
}
int main(){
	cout << "if only i had time to make a gui Lol\n\nLet's begin with alkenes\n---------\nwhat is formed when an alkene react with a halogen (X2) in rtp?\n---------" << endl;
	string ans;
	cin >> ans;
	check(ans, "dihaloalkane");
	cout << "the C=C bond is broken and two halogen atoms attach to its sides.\n\nH2C = CH2 -> BrCH = HCBr\n-----------\nEnter smth" << flush;
	cin >> ans;
	cout << "next: what is formed when an alkene reacts with steam with phosphoric acid catalyst?\n-----------" << endl;
	cin >> ans;
	check(ans, "alcohol");
	cout << "the C=C bond is broken and H-O-H is added to the entire molecule.\n\nH2C=CH2 -> H3C-CH2OH\n------------\nEnter smth" << flush;
	cin >> ans;
	cout << "in that case, what is required for an alcohol to form n alkene?\n------------" << endl;
	cin >> ans;
	check(ans, "conc h3po4");
	cout << "remember that to produce alcohol you added water to an alkene, so to reverse that H2O needs to be eliminated; h3po4 catalyses this so ye\n\nEnter smth" << flush;
	cin >> ans;
	cout << "what forms when an alkene is oxidised by potassium manganate vii KMnO4?\n-------------" << endl;
	cin >> ans;
	check(ans, "diol");
	cout << "the C=C bond is broken and two OH groups are attached to its ends.\n\nH2C=CH2 -> HOCH2-CH2OH\n--------------\nEnter smth" << flush;
	cin >> ans;
	cout << "what is formed when an alkene reacts with H2 and with nickel catalyst?\n---------" << endl;	
	cin >> ans;
	check(ans, "alkane");
	cout << "the C=C bond is broken and both hydrogens attach to both ends (this one is very selfexplanatory you don't need a diagram let's be real lol)\n\nEnter smth" << flush;
	cin >> ans;
	cout << "what is formed when an alkene reacts with a hydrogen halide (HX) at rtp?\n------------------" << endl;
	cin >> ans;
	check(ans, "haloalkane");
	cout << "if you know why an alkene forms a dihaloalkane if it reacts with a halogen then this is literally the same idea lol\nEnter smth" << flush;
	cin >> ans;
	cout << "in that case, what is required for a haloalkane to form an alkene?\n----------" << endl;
	cin >> ans;
	check(ans, "alcoholic koh and heat under reflux");
	cout << "so this is the elimination of hx in the haloalkane;\n\nH3C-CH2Br + KOH -> H2C=CH2 + KBr + H2O\nnotice how the products are water and potassium(or sodium) halide\n-----------------\nEnter smth" << flush;
	cin >> ans;
	cout << "speaking of dihaloalkanes..what is formed when a dihaloalkane reacts with aq. koh under reflux?\n-----------" << endl;
	cin >> ans;
	check(ans, "diol");
	cout << "ok so BrCH2 - CH2Br + 2KOH\nuh yeah you can tell where this will go\nEnter smth" << flush;
	cin >> ans;
	cout << "more alcohol synthesis :3 now, list, in alphabetical order, the reagents that form alcohol through LiAlH4 reduction\n--------------" << endl;
	cin >> ans;
	check(ans, "aldehyde carboxylic acid ketone");
	cout << "this one you kinda just have to know if you see either LiAlH4 or NaBH4\n\nEnter smth" << flush;
	cin >> ans;
	cout << "name another way alcohols can be made\n---------------" << endl;
	cin >> ans;
	check(ans, "haloalkane with aq koh and heat under reflux");
	cout << "so remember that OH- here, since this is aq solution, acts as the nu.phile, so bada bing bada boom betty boop there's your substitution. now you have an alcohol and a potassium halide\n\nEnter smth" << flush;
	cin >> ans;
	cout << "now the reaction vice versa.\n---------------" << endl;
	cin >> ans;
	check(ans, "pcl5, nabr+h2so4, p + i2");
	cout << "ok this one's too complicated i dunno why it's here lmao. basically these are the different ways you can replace that OH- with a halide\n\nEnter smth" << flush;
	cin >> ans;
	cout << "how else can you make haloalkanes anywho?\n---------" << endl;
	cin >> ans;
	check(ans, "alkane and halogen with uv");
	cout << "so this one you should still remember by now that free radical substitution exists and CH4+Br2 becomes CH3Br + HBr\n\nEnter smth" << flush;
	cin >> ans;
	cout << "we're nearly there..back to alcohols, when you react them with acidic kr2cr2o7, what are the possible products? (specify the conditions as well, separate using ;)\n-----------" << endl;
	cin >> ans;
	check(ans, "primary, gentle heat-aldehyde; secondary, heat under reflux-ketone");
	cout << "this one you kinda just remember :p\n\nEnter smth" << flush;
	cin >> ans;
	cout << "now what is the reagent that is used for aldehydes and ketones to form hydroxynitriles?\n-----------------" << endl;
	cin >> ans;
	check(ans, "hcn/kcn");
	cout << "yeah this you probably shouldn't worry too much about, but basically hydroxynitriles contain OH- and CN- so you can kinda deduce something about that\n\nEnter smth" << flush;
	cin >> ans;
	cout << "now, from an aldehyde, what is formed when it is further oxidised by k2cr2o7?\n-------------" << endl;
	cin >> ans;
	check(ans, "carboxylic acid");
	cout << "this one you kinda just remember lol\n\nEnter smth" << flush;
	cin >> ans;
	cout << "now what is formed when a carboxylic acid reacts with an alcohol, h2so4 and in heat?\n------------" << endl;
	cin >> ans;
	check(ans, "ester");
	cout << "yeah carbx. acid + alc = ester, that's always a given.\n\nEnter smth" << flush;
	cin >> ans;
	cout << "last one, i promise ;w; what is formed when carbx. acid reacts with pcl5?\n--------------" << endl;
	cin >> ans;
	check(ans, "acyl chloride");
	cout << "let's be real this one is the least of your worries :P like yeah totally i'll remember R-CO-CL\n\nYou are done, goodbye :33" << endl;
	return 0;

}
