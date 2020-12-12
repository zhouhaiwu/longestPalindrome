#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestPalindrome(char * s) {
    int len = strlen(s);
    //printf("len:%d\n", len);

    char *str2 = (char *)malloc(sizeof(char) * (len + 1));
    int str[1000];
    int start = 0, length = 0;
    if ((len == 1) || (len == 0)) {
        return s;
    }

    int i=0, j=0;
    int i1=0, j1=0;

    
    int k = 0;
    int k1 = 0;
    int k3 = 0;

    int flag = 0;   //  标识，判断是否进行多次的比较
    int flag1 = 0;  //  标识1，判断是否进行相同值的处理
    int flag2 = 0; 


    for(i=1; i<len; i++) {
        printf("***********\n");
        printf("i:%d\n", i);
        while(i < len) {
            if (s[j] == s[i]) {
                str[k3] = i;
                //printf("s[i]:%c\n", s[i]);
                //printf("s[j]:%c\n", s[j]);
                k3++;
            }
            i++;
        }
        if (k3 == 0) {
            //printf("CCCC\n");
            j++;
            i = j;
            if ((j == len - 1) && (flag1 == 0)) {
                str2[0] = s[0];
                str2[1] = '\0';
                //printf("str:%s\n", str2);
                return str2;
            }
        }

        while(k3 > 0) {
            //printf("k3:%d\n", k3);
            flag = 0;
            i = str[k3-1];
            //printf("++++++++++++++\n");
            //printf("i:%d\n", i);
            i1 = i;
            j1 = j;

            while(s[i1] == s[j1]) {
                //printf("i1-j1：%d\n", (i1-j1));
                if ((i1 - j1) >= length) {
                    //printf("EEEE\n");
                    //flag1 = 1;
                    if((((i1 - j1) == 1) || ((i1 - j1) == 2)) && (flag == 0)) {
                        flag1 = 1;
                        flag2 = 1;
                        //printf("FFF\n");
                        start = j1;
                        length = i1 - j1;
                        //printf("AAA\n");
                        k1 = start;
                        for(k1;k1 <= (start + length);k1++) {
                            str2[k] = s[k1];
                            k++;
                        }
                        str2[k] = '\0';
                        start = 0;
                        k = 0;
                        k1 = 0;
                        break;
                    }

                    while (i1 >= j1) {
                        //printf("GGG0\n");
                        flag = 1;
                        j1++;
                        i1--;
                        if(s[i1] != s[j1]) {
                            flag = 2;
                            break;
                        }
                    }
                    //}
                    if(flag ==2) {
                        //printf("flag == 2\n");
                        //printf("k3:%d\n", k3);
                        if(k3 == 1 ){
                            j++;
                            i = j;
                        }
                        break;
                    }
                    if(flag == 1) {
                        //printf("j:%d\n", j);
                        //printf("i:%d\n", i);
                        flag1 = 1;
                        start = j;
                        length = i - j;
                        flag = 0;
                        flag2 = 1;
                        //printf("BBB\n");
                        k1 = start;
                        for(k1; k1 <= (start + length); k1++) {
                            //printf("DDD\n");
                            str2[k] = s[k1];
                            k++;
                        }
                        //printf("CCC\n");
                        str2[k] = '\0';
                        k = 0;
                        k1 = 0;
                        start = 0;
                        //j++;
                        //i = j;
                        break;
                    }
                }
                if ((i1 - j1) < length) {
                    flag2 = 1;
                    break;
                }
            }
            if (flag2 == 1) {
                flag2 = 0;
                k3 = 0;
                //printf("k3k3k3\n");
                j++;
                //printf("j:%d\n", j);
                //printf("***********\n");
                i = j;
                break;
            }
            k3--;
        }
    }

    return str2;
}

int main() {
    //char *str1 = "abcba";
    //char *str1 = "eabcb";
    //char *str1 = "aaaabaaa";
    //char *str1 = "aaaa";
    //char *str1 = "babad";
    //char *str1 = "cbbd";
    //char *str1 = "ac";
    //char *str1 = "aacabdkacaa";
    //char *str1 = "abbcccbbbcaaccbababcbcabca";
    char *str1 = "rgczcpratwyqxaszbuwwcadruayhasynuxnakpmsyhxzlnxmdtsqqlmwnbxvmgvllafrpmlfuqpbhjddmhmbcgmlyeypkfpreddyencsdmgxysctpubvgeedhurvizgqxclhpfrvxggrowaynrtuwvvvwnqlowdihtrdzjffrgoeqivnprdnpvfjuhycpfydjcpfcnkpyujljiesmuxhtizzvwhvpqylvcirwqsmpptyhcqybstsfgjadicwzycswwmpluvzqdvnhkcofptqrzgjqtbvbdxylrylinspncrkxclykccbwridpqckstxdjawvziucrswpsfmisqiozworibeycuarcidbljslwbalcemgymnsxfziattdylrulwrybzztoxhevsdnvvljfzzrgcmagshucoalfiuapgzpqgjjgqsmcvtdsvehewrvtkeqwgmatqdpwlayjcxcavjmgpdyklrjcqvxjqbjucfubgmgpkfdxznkhcejscymuildfnuxwmuklntnyycdcscioimenaeohgpbcpogyifcsatfxeslstkjclauqmywacizyapxlgtcchlxkvygzeucwalhvhbwkvbceqajstxzzppcxoanhyfkgwaelsfdeeviqogjpresnoacegfeejyychabkhszcokdxpaqrprwfdahjqkfptwpeykgumyemgkccynxuvbdpjlrbgqtcqulxodurugofuwzudnhgxdrbbxtrvdnlodyhsifvyspejenpdckevzqrexplpcqtwtxlimfrsjumiygqeemhihcxyngsemcolrnlyhqlbqbcestadoxtrdvcgucntjnfavylip";
    //char *str1 = "cbbd";
    //char *str1 = "aaaaa";
    char *str2;
    str2 = longestPalindrome(str1);
    printf("str2:%s\n", str2);

    return 0;
}