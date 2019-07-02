#include <stdio.h>

char m[] = "MSW{byly_Cm_sIol_lYqUlx_yhdIs_Cn_Wuymul_il_wuff_bcg_pCwnIl_cm_u_Yrwyffyhn_guh_cz_sio_quhn_ni_ayn_bcm_chzilguncihm_sio_wuh_dich_om";

void caesar(int turn)
{
    int i;
    char a;
    printf("For turn %d:", turn);
    for (i = 0; m[i] != '\0'; i++)
    {
        a = m[i];
        printf("%c", (a + turn-'a') % 26 + 'a');
        continue;
        if ('a' <= a && a <= 'z')
        {
            printf("%c", (a - 'a' + turn) % 26 + 'a');
        }
        else if ('A' <= a && a <= 'Z')
        {
            printf("%c", (a - 'A' + turn) % 26 + 'A');
        }
        else if ('0' <= a && a <= '9')
        {
            printf("%c", (a + turn));
        }
        else
        {
            printf("%c", a);
        }
    }
    printf("\n");
}

int main()
{
    int i;
    for (i =0; i < 26; i++)
    {
        caesar(i);
    }
    return 0;
}