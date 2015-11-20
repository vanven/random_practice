/******************************************************************************
 * Coding challenge found on a Support Engineer job posting at Fog Creek
 * Software. (They made Trello!) 
 * http://www.fogcreek.com/Jobs/SupportEngineer/
 *
 * Instructions: Sort the characters in the following string:
 *
 * abcdefghijklmnopqrstuvwxyz_
 *
 * by the number of times the character appears in the following text
 * (descending). (See ugly string below) Now take the sorted string, and drop
 * all the characters after (and including) the _. The remaining word is the
 * answer.
 *
 * ****************************************************************************
 * Not for a job application. I'm still too much of a programming newbie. But
 * just thought I'd give it a try!
 *
 * This ain't pretty. It's just my brain dump of ideas to solve the prob. I
 * started with C++ because the problem reminded me of something in my data
 * structures class where we used C. But then I thought about using JavaScript
 * so I wouldn't have to deal with C-strings vs C++ strings. But, then I ended
 * up with an array of structs instead of using map or whatever I originally
 * thought of using. I could have made a class with methods too, I guess. 
 ******************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using std::string;

// compare two strings
    // iterate through smaller string to find # of times each char appears in larger
    // string. function: countChar();
    // store key/value pairs somehow. 
    // Dictionary? Map? That array of linked lists we used in Data Structures class?
// sort values in descending order
// cut off all chars after and including the underscore.
    // JavaScript slice might be nice here

// Use a struct to hold the key value pairs then just make a regular
// array to hold the structs! Don't go crazy with maps. 
struct CharCount
{
    public:
        char letter[2];
        int occurrences;
};

// countChar function prototype
CharCount countChar(char, string);

// comparison function for std::sort
bool structComp(CharCount a, CharCount b) { return (a.occurrences > b.occurrences); }

int main() {
    CharCount array[27];    // I could make an array of pointers to the struct. But why go to pointer hell on purpose?
    string str1 = "abcdefghijklmnopqrstuvwxyz_",
           str2 = "epqiiqwdiwgyka_vsqtsujeqqicnhyivo_sigwasmkwgsih_akl_gtnkhgikgveidpmtqybpxpnnpbxkwpisgjmdzgh_ojysbtsnsvxvuhguocp_qc_vouxqmg_cetlpmounxnvgldcpem_jodnmklgonocekdkjwkdoilajk_nxujykigsolengqmnqofpseqaamvpsoogaspyhoojennefwvljpvsqtgnceg_hsowqvycjkuxdtfbxfloewkphmvkftjlsasvwid_uqcsgn_ypiqjytygiwyziqdjpxgpuunymadnclpdlmmulitsnqlwciotbmyfuummjynneslnit_lpykdafkpydzkntbud_gigjgmu_uqjjmdzpwteodjpuzndxaqmsjdjjamnwoesajcffkaaoilpyydlkyxauagfcjbabapax_ndlgtpwnud_jpnkiokviqjhyopmjtgtbyoiyfbjdhknimlah_cxfzwspqoscffiyvabtjjuc_liaqbcuomuytdqfy_xaixiiqqdpdsuuimzh_ywwcmodxhfxjplyixotjkeawauxltekptuieekpbokbanumffatbtiacnywhwiqxebnosninpzfjmatvnyuspyeu_ziapvogconld_cxfcytkcp_bvsppz_dw_ndlpkhfzdlxbo_vaflmailjvccgsuclyhojganjqxzmqflpze_hqhlul_ybaagtiuokbzaxhmecolsptiexvvmhbdoelgmcffulcebhlyzd_m_qxkbfvnxykdudpxefsm_aqpqtnhxvswhtowqnbm_mgejjpyumm_mqbkiuulanbmzllmuqlfftmcxtybmijfuwaknefhekwgujpjqgleu_sjtbszotcygiclkwcbmnvgsoqaqqkkgeaslhvfbtlgpnxgpzxp_vyjinlwwfbvtntwogmnpxghabpxxgzlyirrrrrbbcrrrnbjpcrrrqykhrrrscarrrdnlxrrrrtudrrrr_ntrbyrqlddbycypcccqongpgexhnabavrmebeofrxsnrilprveetxaranjyfmrisrewpr_y_lgsrsedbn_rfrieusemhpfa_plkifjipvwaqvnenrrrzybsrbeurbhfrvrrzghr_zpgiyrrrqsnnrrrbhvdrrrqkpdrraqvkeueszfpkj_fm_claw_oetbgurbdocb_rsnzrcyvrvnrvaurbscimurtbriikrfdjlizribdjwkror_gnlzmshwccqcx_huaafbvituxoru_hohxwrrrhnbttrrriyyirrrnibricrxftrrrrvqvrrrrhjorehroldibsmquelwvyjebkolbbnauompgqdhlbnsfbbdiudoeibwstdg_acsazhtgfufidogmyvtya_dfwihtoelucbtlcbaijlcuhfvhesgluiwttsdnqqshnoqumccyqtko_zh_fii_wlsspysdqdpadfvfewlsojavmuaixyxpw_xcwxuatceosdqgmsbbagjmmblouvnywmqqakmmtuasfovol_ogksdukwp_fkxuh_vfhuhfyfvvfqhqxecxsoctcqgpianhtnkbqlltwyhxotfksoewmelxobjgwlyfaeoxsfohhguidoftbsainwovvglynsgjixon_nvuwflsfbca_xnnesvcomceh_gigjxpllckcooagidcpbqxtnejlnlsccocuvcvge_fvjjbyqdkjceia_mkcvbzlzwlxbdjihvpmdcvmssuvktwiqbeivtieol_bu_huumzmlxx_kd_vksmohgzl_fxwfduelqgfkgzxciwmuduozfbaxstxkwegescggkpxfpeenhb_whqhethcateqdvnxhpt__bja_uiyxchmfkblmdwtyp_ktontmufw_isdflelsbgjizxvqbciuadfxxjaqbluofkgkkkhjbvohisfla_cspbmuezqohnyijyimwgdeszutgnaoagbhku_wwdtylbbiyvbpoumgyidw_xwg_fkogabccip_wouclnjcgdpwwxxvvvwkmmbgfeactbcksxqovqthtjfjghijwwhydfieyssbjtfqgqyjnmwfpesljmwapvbptucadontbobnspch_i_dxheklulncdsdnicbnjjjedkaokw_ahcolvbcnmqtoakonpgzjufqlnn_uve_uumaufjasfvfcv_cbcuk_hdzigkahchzfqjphjwcbjwmozyodhu_tsqtafwidgmc_snhhkleyvmzdtawdodzfmekueemnshz_xz";

    // count occurrences of each character in the big, ugly string. Store in
    // struct. store struct in array for later sorting.
    for (int i = 0; i < str1.size(); i++) {
        CharCount result = countChar(str1[i], str2);
        strcpy(array[i].letter, result.letter);
        array[i].occurrences = result.occurrences;
    }

    // print characters number of occurrences
    for (int i = 0; i < (sizeof(array) / sizeof(CharCount)); i++) {
        std::cout << array[i].letter << ": " << array[i].occurrences << std::endl;
    }

    std::cout << std::endl;

    // sort array of characters by their occurances
    std::sort(array, array+27, structComp);

    // print sorted characters
    for (int i = 0; i < (sizeof(array) / sizeof(CharCount)); i++) {     // .size() method doesn't work
        std::cout << array[i].letter;
    }

    std::cout << std::endl;

    return 0;
}

//int countChar(string searchChar, string testString, /*map*/) {
//    int count = 0;
//
//    for (int j = 0; j < testString.size(); j++) {
//        if (searchChar == testString[j]) {
//            count++;
//        }
//    }
//    // store count in map
//}

/* CharCount Struct version */
 CharCount countChar(char searchChar, string testString) {
     int count = 0;
     CharCount val;

     for (int j = 0; j < testString.size(); j++) {
         if (searchChar == testString[j]) {
            count++;
         }
     }

     strcpy(val.letter, &searchChar);
     val.occurrences = count;
     
     return val;
 }


