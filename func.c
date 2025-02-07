#include <stdio.h>
#include"stdf_func.h"
#include<stdlib.h>
#include<string.h>

void open_std_file(){
    unsigned char buff[2];
    int count;
    FILE *fd=fopen("./data/test.std","rb");
    for(int i=0;i<100;i++){
        count=fread(buff,sizeof(unsigned char),1,fd);
        printf("read conut %d fseek %d buff is %x\n",count,i,buff[0]);
        
    }
    fclose(fd);
}
void prf_data_inptr(char *ptr,int len){
    for(int i=0;i<len;i++){
        printf("the NO.%d is %x\n",i,*(ptr+i));
    }
}
int read_headinfo(FILE *fd,Headinfo *headinfo_buff){
    int count;
    count=fread(headinfo_buff,sizeof(Headinfo),1,fd);
    if(count==0){
        printf("read headinfo fail\n");
        return -1;
    }
    return 0;
}

int read_data(FILE *fd,char *data_buff,int len){
    int count;
    count=fread(data_buff,len*sizeof(char),1,fd);
    if(count==0){
        printf("read data count is zore!\n");
        return -1;
    }
    return 0;
}
void read_I1(I1 *i1_buff,char **data_buff,int len,int *pos){    
    if(*pos<len){        
        i1_buff->next=*data_buff+1;
        i1_buff->data=(char *)*data_buff;
        *pos+=1;
        if(*pos!=len){
            *data_buff=i1_buff->next;}                  
    }
    else{
        return;
    }    
}
void read_I2(I2 *i2_buff,char **data_buff,int len,int *pos){
    if(*pos<len){
    i2_buff->next=*data_buff+2;
    i2_buff->data=(short*)*data_buff;
    *pos+=2; 
    if(*pos!=len){
        *data_buff=i2_buff->next;  }      
    }   
    else{
        return;
    }   
}
void read_I4(I4 *i4_buff,char **data_buff,int len,int *pos){
    if(*pos<len){
    i4_buff->next=*data_buff+4;
    i4_buff->data=(long *)*data_buff;
    *pos+=4; 
    if(*pos!=len){
        *data_buff=i4_buff->next;}    
    }   
    else{
        return;
    }   
    
}
void read_U1(U1 *u1_buff,char **data_buff,int len,int *pos){    
    if(*pos<len){        
        u1_buff->next=*data_buff+1;
        u1_buff->data=*data_buff;
        *pos+=1;
        if(*pos!=len){
            *data_buff=u1_buff->next;}                  
    }
    else{
        return;
    }    
}
void read_U2(U2 *u2_buff,char **data_buff,int len,int *pos){
    if(*pos<len){
    u2_buff->next=*data_buff+2;
    u2_buff->data=(unsigned short*)*data_buff;
    *pos+=2; 
    if(*pos!=len){
        *data_buff=u2_buff->next;  }      
    }   
    else{
        return;
    }   
}

void read_U4(U4 *u4_buff,char **data_buff,int len,int *pos){
    if(*pos<len){
    u4_buff->next=*data_buff+4;
    u4_buff->data=(unsigned long *)*data_buff;
    *pos+=4; 
    if(*pos!=len){
        *data_buff=u4_buff->next;}    
    }   
    else{
        return;
    }   
    
}

void read_CN(CN *cn_buff,char **data_buff,int len,int *pos){
    if(*pos<len){        
        char *cn_data;    
        cn_buff->len=**data_buff;    
        printf("len is %d\n",cn_buff->len);
        if(cn_buff->len==0){
            cn_buff->next=*data_buff+1;
            cn_buff->data=*data_buff;
            *data_buff=cn_buff->next;
            *pos+=1;
            return;
        }
        cn_buff->next=*data_buff+cn_buff->len+1;
        cn_buff->data=*data_buff;   
        cn_data=malloc(cn_buff->len*sizeof(char)+1);
        if(cn_data==NULL){
            printf("erro malloc cn data\n");
            return;
        }
        memcpy(cn_data,cn_buff->data+1,cn_buff->len);
        cn_data[cn_buff->len]='\0';
        memcpy(*data_buff,cn_data,cn_buff->len+1); 
        *pos+=(cn_buff->len+1); 
        if(*pos!=len){
            *data_buff=cn_buff->next;}
        free(cn_data);
        
    }   
    else{
        return;
    }   
    
}

void read_R4(R4 *r4_buff,char **data_buff,int len,int *pos){
    if(*pos<len){
    r4_buff->next=*data_buff+4;
    r4_buff->data=(float *)*data_buff;   
    *pos+=4;
    if(*pos!=len){
        *data_buff=(char *)r4_buff->next;
    }   
    
    }
    else{
        return;
    }    
}
void read_B1(B1 *b1_buff,char **data_buff,int len,int *pos){
    if(*pos<len){
        b1_buff->next=*data_buff+1;
        b1_buff->data=*data_buff;
        *pos+=1;
        if(*pos!=len){
            *data_buff=b1_buff->next;
        }
    }
    else{
        return;
    }
    
}

void read_BN(BN *bn_buff,char **data_buff,int len,int *pos){
    if(*pos<len){        
        char *bn_data;    
        bn_buff->len=**data_buff;    
        if(bn_buff->len==0){
            bn_buff->next=*data_buff+1;
            bn_buff->data=*data_buff;
            *data_buff=bn_buff->next;
            *pos+=1;
            return;
        }
        bn_buff->next=*data_buff+bn_buff->len+1;
        bn_buff->data=*data_buff;   
        bn_data=malloc(bn_buff->len*sizeof(char)+1);
        if(bn_data==NULL){
            printf("erro malloc cn data\n");
            return;
        }
        memcpy(bn_data,bn_buff->data+1,bn_buff->len);
        bn_data[bn_buff->len]='\0';
        memcpy(*data_buff,bn_data,bn_buff->len+1); 
        *pos+=(bn_buff->len+1); 
        if(*pos!=len){
            *data_buff=bn_buff->next;}
        free(bn_data);
        
    }   
    else{
        return;
    }   
    
}

void read_DN(DN *dn_buff,char **data_buff,int len,int *pos){
    if(*pos<len){
        dn_buff->len=*(unsigned short *)*data_buff;
        //printf("dn lens is %d\n",dn_buff->len);
        dn_buff->next=*data_buff+dn_buff->len/8+2;
        *data_buff=dn_buff->next;
        *pos=*pos+dn_buff->len/8+2;
    }else{
        return;
    }

}

void read_KXU2(Kxu2 *kxu2_buff,char **data_buff,int k,int len,int *pos){
    if(*pos<len){
        kxu2_buff->data=(unsigned short*)*data_buff;
        kxu2_buff->next=(unsigned char*)*data_buff+2*k;
        *data_buff=(char *)kxu2_buff->next;
        *pos=2*k+*pos;
    }else{
        return;
    }
}
void read_KXN1(Kxn1 *kxn1_buff,char **data_buff,int k,int len,int *pos){
    if(*pos<len){
        kxn1_buff->data=*data_buff;
        kxn1_buff->next=*data_buff+k;
        *data_buff=kxn1_buff->next;
        *pos=k+*pos;
    }else{
        return;
    }
}

void get_pir_data(Pir *pir_buff,char **data_buff,int len,int *pos){
    read_U1(&pir_buff->HEAD_NUM,data_buff,len,pos);
    read_U1(&pir_buff->SITE_NUM,data_buff,len,pos);
}

void get_prr_data(Prr *prr_buff,char **data_buff,int len,int *pos){
    read_U1(&prr_buff->HEAD_NUM,data_buff,len,pos);
    read_U1(&prr_buff->SITE_NUM,data_buff,len,pos);
    read_B1(&prr_buff->PART_FLG,data_buff,len,pos);    
    read_U2(&prr_buff->NUM_TEST,data_buff,len,pos);
    read_U2(&prr_buff->HARD_BIN,data_buff,len,pos);
    read_U2(&prr_buff->SOFT_BIN,data_buff,len,pos);
    read_I2(&prr_buff->X_COORD,data_buff,len,pos);
    read_I2(&prr_buff->Y_COORD,data_buff,len,pos);
    read_U4(&prr_buff->TEST_T,data_buff,len,pos);
    read_CN(&prr_buff->PART_ID,data_buff,len,pos);
    read_CN(&prr_buff->PART_TXT,data_buff,len,pos);
    read_BN(&prr_buff->PART_FIX,data_buff,len,pos);
}
void get_ftr_data(Ftr *ftr_buff,char **data_buff,int len,int *pos){
    printf("lens is %d\n",len);
    read_U4(&ftr_buff->TEST_NUM,data_buff,len,pos);
    read_U1(&ftr_buff->HEAD_NUM,data_buff,len,pos);
    read_U1(&ftr_buff->SITE_NUM,data_buff,len,pos);
    read_B1(&ftr_buff->TEST_FLG,data_buff,len,pos);
    read_B1(&ftr_buff->OPT_FLAG,data_buff,len,pos);        
    read_U4(&ftr_buff->CYCL_CNT,data_buff,len,pos);       
    read_U4(&ftr_buff->REL_VADR,data_buff,len,pos);
    read_U4(&ftr_buff->REPT_CNT,data_buff,len,pos);    
    read_U4(&ftr_buff->NUM_FAIL,data_buff,len,pos);
    read_I4(&ftr_buff->XFAIL_AD,data_buff,len,pos);
    read_I4(&ftr_buff->YFAIL_AD,data_buff,len,pos);    
    read_I2(&ftr_buff->VECT_OFF,data_buff,len,pos);
    read_U2(&ftr_buff->RTN_ICNT,data_buff,len,pos);    
    read_U2(&ftr_buff->PGM_ICNT,data_buff,len,pos);        
    read_KXU2(&ftr_buff->RTN_INDX,data_buff,*ftr_buff->RTN_ICNT.data,len,pos);
    read_KXN1(&ftr_buff->RTN_STAT,data_buff,*ftr_buff->RTN_ICNT.data,len,pos);
    read_KXU2(&ftr_buff->PGM_INDX,data_buff,*ftr_buff->PGM_ICNT.data,len,pos);
    read_KXN1(&ftr_buff->PGM_STAT,data_buff,*ftr_buff->PGM_ICNT.data,len,pos);       
    read_DN(&ftr_buff->FAIL_PIN,data_buff,len,pos); 
    read_CN(&ftr_buff->VECT_NAM,data_buff,len,pos);
    read_CN(&ftr_buff->TIME_SET,data_buff,len,pos);
    read_CN(&ftr_buff->OP_CODE,data_buff,len,pos);    
    read_CN(&ftr_buff->TEST_TXT,data_buff,len,pos);
    read_CN(&ftr_buff->ALARM_ID,data_buff,len,pos);
    read_CN(&ftr_buff->PROG_TXT,data_buff,len,pos);    
    read_CN(&ftr_buff->RSLT_TXT,data_buff,len,pos);
    read_U1(&ftr_buff->PATG_NUM,data_buff,len,pos);
    read_DN(&ftr_buff->SPIN_MAP,data_buff,len,pos);
    printf("end of len is %d\n",*pos);
}

void get_ptr_data(Ptr *ptr_buff,char **data_buff,int len,int *pos){   
    //printf("%d\n",len); 
    read_U4(&ptr_buff->TEST_NUM,data_buff,len,pos);
    read_U1(&ptr_buff->HEAD_NUM,data_buff,len,pos);  
    //printf("1 %d\n",*ptr_buff->HEAD_NUM.data);  
    read_U1(&ptr_buff->SITE_NUM,data_buff,len,pos);  
    //printf("2\n");  
    read_B1(&ptr_buff->TEST_FLG,data_buff,len,pos);  
    //printf("3:%x\n",*ptr_buff->TEST_FLG.data);  
    read_B1(&ptr_buff->PARM_FLG,data_buff,len,pos);   
    //printf("4:%x\n",*ptr_buff->PARM_FLG.data); 
    read_R4(&ptr_buff->RESULT,data_buff,len,pos);    
    //printf("5:%f\n",*ptr_buff->RESULT.data);
    read_CN(&ptr_buff->TEST_TXT,data_buff,len,pos);
    //printf("6:%s pos is %d\n",ptr_buff->TEST_TXT.data,*pos);  
    // prf_data_inptr(*data_buff,15);  
    read_CN(&ptr_buff->ALARM_ID,data_buff,len,pos);    
    //printf("7:%s pos is %d\n",ptr_buff->ALARM_ID.data,*pos);  
    // prf_data_inptr(*data_buff,15);
    read_B1(&ptr_buff->OPT_FLAG,data_buff,len,pos);
    //printf("8:%x pos is %d\n",*ptr_buff->OPT_FLAG.data,*pos);
    read_I1(&ptr_buff->RES_SCAL,data_buff,len,pos);
    read_I1(&ptr_buff->LLM_SCAL,data_buff,len,pos);
    read_I1(&ptr_buff->HLM_SCAL,data_buff,len,pos);
    read_R4(&ptr_buff->LO_LIMIT,data_buff,len,pos);
    read_R4(&ptr_buff->HI_LIMIT,data_buff,len,pos);
    read_CN(&ptr_buff->UNITS,data_buff,len,pos);
    read_CN(&ptr_buff->C_RESFMT,data_buff,len,pos);
    read_CN(&ptr_buff->C_LLMFMT,data_buff,len,pos);
    read_CN(&ptr_buff->C_HLMFMT,data_buff,len,pos);
    read_R4(&ptr_buff->LO_SPEC,data_buff,len,pos);    
    read_R4(&ptr_buff->HI_SPEC,data_buff,len,pos);
}

void get_tsr_data(Tsr *tsr_buff,char **data_buff,int len,int *pos){
    //printf("start tsr parase\n");
    read_U1(&tsr_buff->HEAD_NUM,data_buff,len,pos);
    read_U1(&tsr_buff->SITE_NUM,data_buff,len,pos);
    read_U1(&tsr_buff->TEST_TYP,data_buff,len,pos);
    read_U4(&tsr_buff->TEST_NUM,data_buff,len,pos);
    read_U4(&tsr_buff->EXEC_CNT,data_buff,len,pos);
    read_U4(&tsr_buff->FAIL_CNT,data_buff,len,pos);
    read_U4(&tsr_buff->ALRM_CNT,data_buff,len,pos);    
    read_CN(&tsr_buff->TEST_NAM,data_buff,len,pos);    
    read_CN(&tsr_buff->SEQ_NAME,data_buff,len,pos);    
    read_CN(&tsr_buff->TEST_LBL,data_buff,len,pos);    
    read_B1(&tsr_buff->OPT_FLAG,data_buff,len,pos);    
    read_R4(&tsr_buff->TEST_TIM,data_buff,len,pos);
    read_R4(&tsr_buff->TEST_MIN,data_buff,len,pos);
    read_R4(&tsr_buff->TEST_MAX,data_buff,len,pos);
    read_R4(&tsr_buff->TST_SUMS,data_buff,len,pos);
    read_R4(&tsr_buff->TST_SQRS,data_buff,len,pos);
    }

void get_mir_data(Mir *mir_buff,char **data_buff,int len,int *pos){    
    read_U4(&mir_buff->SETUP_T,data_buff,len,pos);    
    read_U4(&mir_buff->START_T,data_buff,len,pos);
    read_U1(&mir_buff->STAT_NUM,data_buff,len,pos);
    read_U1(&mir_buff->MODE_COD,data_buff,len,pos); 
    read_U1(&mir_buff->RTST_COD,data_buff,len,pos); 
    read_U1(&mir_buff->PROT_COD,data_buff,len,pos); 
    read_U2(&mir_buff->BURN_TIM,data_buff,len,pos);  
    read_U1(&mir_buff->CMOD_COD,data_buff,len,pos);  
    read_CN(&mir_buff->LOT_ID,data_buff,len,pos);
    read_CN(&mir_buff->PART_TYP,data_buff,len,pos);
    read_CN(&mir_buff->NODE_NAM,data_buff,len,pos);
    read_CN(&mir_buff->TSTR_TYP,data_buff,len,pos);
    read_CN(&mir_buff->JOB_NAM,data_buff,len,pos);
    read_CN(&mir_buff->JOB_REV,data_buff,len,pos);
    read_CN(&mir_buff->SBLOT_ID,data_buff,len,pos);
    read_CN(&mir_buff->OPER_NAM,data_buff,len,pos);
    read_CN(&mir_buff->EXEC_TYP,data_buff,len,pos);
    read_CN(&mir_buff->EXEC_VER,data_buff,len,pos);
    read_CN(&mir_buff->TEST_COD,data_buff,len,pos);
    read_CN(&mir_buff->TST_TEMP,data_buff,len,pos);
    read_CN(&mir_buff->USER_TXT,data_buff,len,pos);
    read_CN(&mir_buff->AUX_FILE,data_buff,len,pos);
    read_CN(&mir_buff->PKG_TYP,data_buff,len,pos);
    read_CN(&mir_buff->FAMLY_ID,data_buff,len,pos);
    read_CN(&mir_buff->DATE_COD,data_buff,len,pos);
    read_CN(&mir_buff->FACIL_ID,data_buff,len,pos);
    read_CN(&mir_buff->FLOOR_ID,data_buff,len,pos);
    read_CN(&mir_buff->PROC_ID,data_buff,len,pos);
    read_CN(&mir_buff->OPER_FRQ,data_buff,len,pos);
    read_CN(&mir_buff->SPEC_NAM,data_buff,len,pos);
    read_CN(&mir_buff->SPEC_VER,data_buff,len,pos);
    read_CN(&mir_buff->FLOW_ID,data_buff,len,pos);
    read_CN(&mir_buff->SETUP_ID,data_buff,len,pos);
    read_CN(&mir_buff->DSGN_REV,data_buff,len,pos);
    read_CN(&mir_buff->ENG_ID,data_buff,len,pos);
    read_CN(&mir_buff->ROM_COD,data_buff,len,pos);
    read_CN(&mir_buff->SERL_NUM,data_buff,len,pos);
    read_CN(&mir_buff->SUPR_NAM,data_buff,len,pos); 
    }

int main(){
    char *buff_free;
    char **buff_m;
    char **data_buff;
    Ftr *type_buff;
    FILE *fd;
    Headinfo *headinfo;
    data_buff=(char **)malloc(sizeof(char *));
    headinfo=(Headinfo *)malloc(sizeof(Headinfo));
    fd=fopen("./data/test.std","rb");
    if(fd==NULL){
        printf("open file fail\n");
        return -1;
    }
    printf("open file success\n");
    int read_status;
    do{
        read_status=read_headinfo(fd,headinfo);
        if(read_status==-1){
            printf("read status -1 fail\n");
            free(headinfo);
            free(*data_buff);
            fclose(fd);
            printf("process end\n");
            return -1;
        }

        *data_buff=(char *)malloc(headinfo->REC_LEN*sizeof(char));        
        read_status=read_data(fd,*data_buff,headinfo->REC_LEN);
        // printf("the type is %d %d\n",headinfo->REC_TYP,headinfo->REC_SUB);
        
        if(read_status==-1){
            printf("read data fail\n");
            free(headinfo);
            free(*data_buff);
            fclose(fd);
            printf("process end\n");
            return -1;
        }
        
        if((headinfo->REC_TYP==15)&&(headinfo->REC_SUB==20)){
            //prf_data_inptr(*data_buff,headinfo->REC_LEN);
            type_buff=(Ftr *)malloc(sizeof(Ftr)+10);  
            if(type_buff==NULL){
                printf("malloc fail\n");
                return -1;
            } 
            int pos=1;            
            get_ftr_data(type_buff,data_buff,headinfo->REC_LEN,&pos);
            
            printf("head number is %s\n",type_buff->TEST_TXT.data);            
            // printf("test name is %s\n",type_buff->PROG_TXT.data);
            
            free(type_buff);

        }

    }while(read_status==0);
    free(headinfo);
    free(*data_buff);
    fclose(fd);
    printf("process end\n");
    return 0;
}