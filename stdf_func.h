#include <stdio.h>
typedef struct headinfo{
    unsigned short REC_LEN;// U*2 Bytes of data following header
    unsigned char REC_TYP;// U*1 Record type (15)
    unsigned char REC_SUB;// U*1 Record sub-type (15)
}Headinfo;
typedef struct b1{
    unsigned char *data;// b*1 fix length byte
    unsigned char *next;
}B1;
typedef struct bn{
    unsigned char *data;
    unsigned char len;
    unsigned char *next;
}BN;
typedef struct i1{
    char *data;
    unsigned char *next;
}I1;
typedef struct u1{
    unsigned char *data;
    unsigned char *next;
}U1;
typedef struct u2{
    unsigned short *data;// U*2 Two byte unsigned integer unsigned short
    unsigned char *next;
}U2;

typedef struct u4{
    unsigned long *data;//U*4 Four byte unsigned integer unsigned long
    unsigned char *next;
}U4;

typedef struct cn{
    unsigned char *data;
    unsigned char len;
    unsigned char *next;
}CN;
typedef struct dn{
    unsigned char *data;
    /*First data item in least significant bit of the third byte of the array
    (first two bytes are count).Unused bits at the high order end of the last byte must be zero.
    */
    unsigned short len;//unsigned count of bits to follow
    unsigned char *next;
}DN;
typedef struct r4{
    float *data;
    unsigned char *next;
}R4;

typedef struct r8{
    double *data;
    unsigned char *next;
}R8;
typedef struct i2{
    short *data;
    unsigned char *next;
}I2;

typedef struct i4{
    long *data;//I*4 Four byte signed integer signed long
    unsigned char *next;
}I4;

typedef struct kxu2{
    unsigned short *data;
    unsigned char *next;
}Kxu2;

typedef struct kxn1{
    unsigned char *data;   
    unsigned char *next;
}Kxn1;

typedef struct mir{
    U4 SETUP_T;// U*4 Date and time of job setup
    U4 START_T;// U*4 Date and time first part tested
    U1 STAT_NUM;// U*1 Tester station number
    U1 MODE_COD;// C*1;// Test mode code (e.g. prod, dev) space
    U1 RTST_COD;// C*1 Lot retest code space
    U1 PROT_COD;// C*1 Data protection code space
    U2 BURN_TIM;// U*2 Burn-in time (in minutes) 65,535
    U1 CMOD_COD;// C*1 Command mode code space
    CN LOT_ID;// 1 C*n Lot ID (customer specified)
    CN PART_TYP;// 2 C*n Part Type (or product ID)
    CN NODE_NAM;// 3 C*n Name of node that generated data
    CN TSTR_TYP;// 4 C*n Tester type
    CN JOB_NAM;// 5 C*n Job name (test program name)
    CN JOB_REV;// 6 C*n Job (test program) revision number length byte = 0
    CN SBLOT_ID;// 7 C*n Sublot ID length byte = 0
    CN OPER_NAM;// 8 C*n Operator name or ID (at setup time) length byte = 0
    CN EXEC_TYP;// 9 C*n Tester executive software type length byte = 0
    CN EXEC_VER;// 10 C*n Tester exec software version number length byte = 0
    CN TEST_COD;// 11 C*n Test phase or step code length byte = 0
    CN TST_TEMP;// 12 C*n Test temperature length byte = 0
    CN USER_TXT;// 13 C*n Generic user text length byte = 0
    CN AUX_FILE;// 14 C*n Name of auxiliary data file length byte = 0
    CN PKG_TYP;// 15 C*n Package type length byte = 0
    CN FAMLY_ID;// 16 C*n Product family ID length byte = 0
    CN DATE_COD;// 17 C*n Date code length byte = 0
    CN FACIL_ID;// 18 C*n Test facility ID length byte = 0
    CN FLOOR_ID;// 19 C*n Test floor ID length byte = 0
    CN PROC_ID;// 20 C*n Fabrication process ID length byte = 0
    CN OPER_FRQ;// 21 C*n Operation frequency or step length byte = 0
    CN SPEC_NAM;// 22 C*n Test specification name length byte = 0
    CN SPEC_VER;// 23 C*n Test specification version number length byte = 0
    CN FLOW_ID;// 24 C*n Test flow ID length byte = 0
    CN SETUP_ID;// 25 C*n Test setup ID length byte = 0
    CN DSGN_REV;// 26 C*n Device design revision length byte = 0
    CN ENG_ID;// 27 C*n Engineering lot ID length byte = 0
    CN ROM_COD;// 28 C*n ROM code ID length byte = 0
    CN SERL_NUM;// 29 C*n Tester serial number length byte = 0
    CN SUPR_NAM;// 30 C*n Supervisor name or ID length byte = 0
}Mir;

typedef struct tsr{
    U1 HEAD_NUM ; // Test head number
    U1 SITE_NUM ; // Test site number
    U1 TEST_TYP ; // Test type
    U4 TEST_NUM ; // Test number
    U4 EXEC_CNT ; // Number of test executions
    U4 FAIL_CNT ; // Number of test failures
    U4 ALRM_CNT ; // Number of alarmed tests
    CN TEST_NAM ; // Test name
    CN SEQ_NAME ; // Sequencer (program segment/flow) name
    CN TEST_LBL ; // Test label or text
    B1 OPT_FLAG ; // Optional data flag
    R4 TEST_TIM ; // Average test execution time in seconds
    R4 TEST_MIN ; // Lowest test result value
    R4 TEST_MAX ; // Highest test result value
    R4 TST_SUMS ; // Sum of test result values
    R4 TST_SQRS ; // Sum of squares of test result values
}Tsr;

typedef struct ptr{
    U4 TEST_NUM;      // U*4 Test number
    U1 HEAD_NUM;     // U*1 Test head number
    U1 SITE_NUM;     // U*1 Test site number
    B1 TEST_FLG;  // B*1 Test flags (fail, alarm, etc.)
    B1 PARM_FLG;  // B*1 Parametric test flags (drift, etc.)
    R4 RESULT;               // R*4 Test result TEST_FLG bit 1 = 1
    CN TEST_TXT;    // C*n Test description text or label length byte = 0
    CN ALARM_ID;    // C*n Name of alarm length byte = 0
    B1 OPT_FLAG;  // B*1 Optional data flag See note
    I1 RES_SCAL;     // I*1 Test results scaling exponent OPT_FLAG bit 0 = 1
    I1 LLM_SCAL;     // I*1 Low limit scaling exponent OPT_FLAG bit 4 or 6 = 1
    I1 HLM_SCAL;     // I*1 High limit scaling exponent OPT_FLAG bit 5 or 7 = 1
    R4 LO_LIMIT;             // R*4 Low test limit value OPT_FLAG bit 4 or 6 = 1
    R4 HI_LIMIT;             // R*4 High test limit value OPT_FLAG bit 5 or 7 = 1
    CN UNITS;       // C*n Test units length byte = 0
    CN C_RESFMT;    // C*n ANSI C result format string length byte = 0
    CN C_LLMFMT;    // C*n ANSI C low limit format string length byte = 0
    CN C_HLMFMT;    // C*n ANSI C high limit format string length byte = 0
    R4 LO_SPEC;              // R*4 Low specification limit value OPT_FLAG bit 2 = 1
    R4 HI_SPEC;              // R*4 High specification limit value OPT_FLAG bit 3 = 1
}Ptr;//REC_TYP(15) AND REC_SUB(10)

typedef struct pir {
    U1  HEAD_NUM ; // Test head number
    U1  SITE_NUM ; // Test site number
} Pir;

typedef struct prr {
    U1  HEAD_NUM ; //Test head number
    U1  SITE_NUM ; //Test site number
    B1  PART_FLG ; //Part information flag
    U2  NUM_TEST ; //Number of tests executed
    U2  HARD_BIN ; //Hardware bin number
    U2  SOFT_BIN ; //Software bin number
    I2  X_COORD  ; //(Wafer) X coordinate
    I2  Y_COORD  ; //(Wafer) Y coordinate
    U4  TEST_T   ; //Elapsed test time in milliseconds
    CN  PART_ID  ; //Part identification
    CN  PART_TXT ; //Part description text
    BN  PART_FIX ; //Part repair information
}Prr;

typedef struct ftr {
    U4      TEST_NUM ; // Test number
    U1      HEAD_NUM ; // Test head number
    U1      SITE_NUM ; // Test site number
    B1      TEST_FLG ; // Test flags (fail, alarm, etc.)
    B1      OPT_FLAG ; // Optional data flag
    U4      CYCL_CNT ; // Cycle count of vector
    U4      REL_VADR ; // Relative vector address
    U4      REPT_CNT ; // Repeat count of vector
    U4      NUM_FAIL ; // Number of pins with 1 or more failures
    I4      XFAIL_AD ; // X logical device failure address
    I4      YFAIL_AD ; // Y logical device failure address
    I2      VECT_OFF ; // Offset from vector of interest
    U2      RTN_ICNT ; // Count j of return data PMR indexes
    U2      PGM_ICNT ; // Count k of programmed state indexes
    Kxu2    RTN_INDX ; // Array j of return data PMR indexes
    Kxn1    RTN_STAT ; // Array j of returned states
    Kxu2    PGM_INDX ; // Array k of programmed state indexes
    Kxn1    PGM_STAT ; // Array k of programmed states
    DN      FAIL_PIN ; // Failing pin bitfield
    CN      VECT_NAM ; // Vector module pattern name
    CN      TIME_SET ; // Time set name
    CN      OP_CODE  ; // Vector Op Code
    CN      TEST_TXT ; // Descriptive text or label
    CN      ALARM_ID ; // Name of alarm
    CN      PROG_TXT ; // Additional programmed information
    CN      RSLT_TXT ; // Additional result information
    U1      PATG_NUM ; // Pattern generator number
    DN      SPIN_MAP ; // Bit map of enabled comparators
} Ftr;