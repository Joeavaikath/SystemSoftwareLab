#include<stdio.h>
#include<string.h>

void main()
{

        FILE *in_file,*sym_tab,*op_tab;
        int op1,start_ad,loc_ctr,o,len,found=0;
        char la[20],m1[20],op[20],otp[20];

        in_file=fopen("input.txt","r");
        sym_tab=fopen("symtab.txt","w");

        fscanf(in_file,"%s %s %d",la,m1,&op1);

        if(strcmp(m1,"START")==0)
        {
                start_ad=op1;
                loc_ctr=start_ad;
                printf("\t%s\t%s\t%d\n",la,m1,op1);
        }
        else
                loc_ctr=0;
                fscanf(in_file,"%s %s",la,m1);
        while(!feof(in_file))
        {

                found=0;
                fscanf(in_file,"%s",op);
                printf("\n%d\t%s\t%s\t%s\n",loc_ctr,la,m1,op);
                if(strcmp(la,"-")!=0)
                        fprintf(sym_tab,"\n%d\t%s\n",loc_ctr,la);

                op_tab=fopen("optab.txt","r");
                fscanf(op_tab,"%s %d",otp,&o);
                while(!feof(op_tab))
                {
                        if(strcmp(m1,otp)==0)
                        {
                                loc_ctr=loc_ctr+3;
                                found=1;
                                break;
                        }
                        fscanf(op_tab,"%s %d",otp,&o);
                }
                fclose(op_tab);

                        if(strcmp(m1,"WORD")==0)
                                loc_ctr+=3;
                        else if(strcmp(m1,"RESW")==0)
                        {
                                op1=atoi(op);
                                loc_ctr*=op1;
                        }
                        else if(strcmp(m1,"BYTE")==0)
                        {
                                if(op[0]=='X')
                                        loc_ctr+=1;
                                else
                                {
                                        len=strlen(op)-3;
                                        loc_ctr+=len;
                                }
                        }
                        else if(strcmp(m1,"RESB")==0)
                        {
                                op1=atoi(op);
                                loc_ctr+=1;
                        }
                }

                        fscanf(in_file,"%s %s",la,m1);
                        if(strcmp(m1,"END")==0)
                                printf("Program length = %d",loc_ctr-start_ad);
                        fclose(in_file);
                        fclose(sym_tab);
}
