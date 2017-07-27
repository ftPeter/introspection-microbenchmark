#ifndef BLOCK_MEMORY_FUNCTIONS_H_
#define BLOCK_MEMORY_FUNCTIONS_H_

// dummy function to prevent optimising out the read_memory load
static volatile uint64_t  use_result_dummy;
void use_int( int result )
{
    use_result_dummy += result; 
}

// dummy function to prevent optimising out the read_memory load
static volatile float use_float_dummy;
void use_float( float result )
{
    use_float_dummy += result;
}


// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory( uint64_t access_bytes, TYPE *memory_block )
{
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        sum+=p[0];sum+=p[1]; sum+=p[2];sum+=p[3];
        sum+=p[4];sum+=p[5]; sum+=p[6];sum+=p[7];
        sum+=p[8];sum+=p[9]; sum+=p[10];sum+=p[11];
        sum+=p[12];sum+=p[13]; sum+=p[14];sum+=p[15];
        sum+=p[16];sum+=p[17]; sum+=p[18];sum+=p[19];
        sum+=p[20];sum+=p[21]; sum+=p[22];sum+=p[23];
        sum+=p[24];sum+=p[25]; sum+=p[26];sum+=p[27];
        sum+=p[28];sum+=p[29]; sum+=p[30];sum+=p[31];
        sum+=p[32];sum+=p[33]; sum+=p[34];sum+=p[35];
        sum+=p[36];sum+=p[37]; sum+=p[38];sum+=p[39];
        sum+=p[40];sum+=p[41]; sum+=p[42];sum+=p[43];
        sum+=p[44];sum+=p[45]; sum+=p[46];sum+=p[47];
        sum+=p[48];sum+=p[49]; sum+=p[50];sum+=p[51];
        sum+=p[52];sum+=p[53]; sum+=p[54];sum+=p[55];
        sum+=p[56];sum+=p[57]; sum+=p[58];sum+=p[59];
        sum+=p[60];sum+=p[61]; sum+=p[62];sum+=p[63];
        sum+=p[64];sum+=p[65]; sum+=p[66];sum+=p[67];
        sum+=p[68];sum+=p[69]; sum+=p[70];sum+=p[71];
        sum+=p[72];sum+=p[73]; sum+=p[74];sum+=p[75];
        sum+=p[76];sum+=p[77]; sum+=p[78];sum+=p[79];
        sum+=p[80];sum+=p[81]; sum+=p[82];sum+=p[83];
        sum+=p[84];sum+=p[85]; sum+=p[86];sum+=p[87];
        sum+=p[88];sum+=p[89]; sum+=p[90];sum+=p[91];
        sum+=p[92];sum+=p[93]; sum+=p[94];sum+=p[95];
        sum+=p[96];sum+=p[97]; sum+=p[98];sum+=p[99];
        sum+=p[100];sum+=p[101]; sum+=p[102];sum+=p[103];
        sum+=p[104];sum+=p[105]; sum+=p[106];sum+=p[107];
        sum+=p[108];sum+=p[109]; sum+=p[110];sum+=p[111];
        sum+=p[112];sum+=p[113]; sum+=p[114];sum+=p[115];
        sum+=p[116];sum+=p[117]; sum+=p[118];sum+=p[119];
        sum+=p[120];sum+=p[121]; sum+=p[122];sum+=p[123];
        sum+=p[124];sum+=p[125]; sum+=p[126];sum+=p[127];
        p += 128;
    }
    use_int(sum);
    return access_bytes;
}

// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_1( uint64_t access_bytes, TYPE *memory_block )
{
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        sum+=p[0];sum+=p[1];sum+=p[2];sum+=p[3]; sum+=p[4];sum+=p[5];sum+=p[6];sum+=p[7]; sum+=2.5;
        sum+=p[8];sum+=p[9];sum+=p[10];sum+=p[11]; sum+=p[12];sum+=p[13];sum+=p[14];sum+=p[15]; sum+=2.5;
        sum+=p[16];sum+=p[17];sum+=p[18];sum+=p[19]; sum+=p[20];sum+=p[21];sum+=p[22];sum+=p[23]; sum+=2.5;
        sum+=p[24];sum+=p[25];sum+=p[26];sum+=p[27]; sum+=p[28];sum+=p[29];sum+=p[30];sum+=p[31]; sum+=2.5;
        sum+=p[32];sum+=p[33];sum+=p[34];sum+=p[35]; sum+=p[36];sum+=p[37];sum+=p[38];sum+=p[39]; sum+=2.5;
        sum+=p[40];sum+=p[41];sum+=p[42];sum+=p[43]; sum+=p[44];sum+=p[45];sum+=p[46];sum+=p[47]; sum+=2.5;
        sum+=p[48];sum+=p[49];sum+=p[50];sum+=p[51]; sum+=p[52];sum+=p[53];sum+=p[54];sum+=p[55]; sum+=2.5;
        sum+=p[56];sum+=p[57];sum+=p[58];sum+=p[59]; sum+=p[60];sum+=p[61];sum+=p[62];sum+=p[63]; sum+=2.5;
        sum+=p[64];sum+=p[65];sum+=p[66];sum+=p[67]; sum+=p[68];sum+=p[69];sum+=p[70];sum+=p[71]; sum+=2.5;
        sum+=p[72];sum+=p[73];sum+=p[74];sum+=p[75]; sum+=p[76];sum+=p[77];sum+=p[78];sum+=p[79]; sum+=2.5;
        sum+=p[80];sum+=p[81];sum+=p[82];sum+=p[83]; sum+=p[84];sum+=p[85];sum+=p[86];sum+=p[87]; sum+=2.5;
        sum+=p[88];sum+=p[89];sum+=p[90];sum+=p[91]; sum+=p[92];sum+=p[93];sum+=p[94];sum+=p[95]; sum+=2.5;
        sum+=p[96];sum+=p[97];sum+=p[98];sum+=p[99]; sum+=p[100];sum+=p[101];sum+=p[102];sum+=p[103]; sum+=2.5;
        sum+=p[104];sum+=p[105];sum+=p[106];sum+=p[107]; sum+=p[108];sum+=p[109];sum+=p[110];sum+=p[111]; sum+=2.5;
        sum+=p[112];sum+=p[113];sum+=p[114];sum+=p[115]; sum+=p[116];sum+=p[117];sum+=p[118];sum+=p[119]; sum+=2.5;
        sum+=p[120];sum+=p[121];sum+=p[122];sum+=p[123]; sum+=p[124];sum+=p[125];sum+=p[126];sum+=p[127]; sum+=2.5;
        p += 128;
    }
    use_int(sum);
    return access_bytes;
}

// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_2( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        sum+=p[0];sum+=p[1];sum+=p[2];sum+=p[3]; sum+=2.5; sum+=p[4];sum+=p[5];sum+=p[6];sum+=p[7];
        sum+=p[8];sum+=p[9];sum+=p[10];sum+=p[11]; sum+=2.5; sum+=p[12];sum+=p[13];sum+=p[14];sum+=p[15]; sum+=2.5;
        sum+=p[16];sum+=p[17];sum+=p[18];sum+=p[19]; sum+=2.5; sum+=p[20];sum+=p[21];sum+=p[22];sum+=p[23];
        sum+=p[24];sum+=p[25];sum+=p[26];sum+=p[27]; sum+=2.5; sum+=p[28];sum+=p[29];sum+=p[30];sum+=p[31]; 
        sum+=p[32];sum+=p[33];sum+=p[34];sum+=p[35]; sum+=2.5; sum+=p[36];sum+=p[37];sum+=p[38];sum+=p[39];
        sum+=p[40];sum+=p[41];sum+=p[42];sum+=p[43]; sum+=2.5; sum+=p[44];sum+=p[45];sum+=p[46];sum+=p[47];
        sum+=p[48];sum+=p[49];sum+=p[50];sum+=p[51]; sum+=2.5; sum+=p[52];sum+=p[53];sum+=p[54];sum+=p[55];
        sum+=p[56];sum+=p[57];sum+=p[58];sum+=p[59]; sum+=2.5; sum+=p[60];sum+=p[61];sum+=p[62];sum+=p[63];
        sum+=p[64];sum+=p[65];sum+=p[66];sum+=p[67]; sum+=2.5; sum+=p[68];sum+=p[69];sum+=p[70];sum+=p[71];
        sum+=p[72];sum+=p[73];sum+=p[74];sum+=p[75]; sum+=2.5; sum+=p[76];sum+=p[77];sum+=p[78];sum+=p[79]; sum+=2.5;
        sum+=p[80];sum+=p[81];sum+=p[82];sum+=p[83]; sum+=2.5; sum+=p[84];sum+=p[85];sum+=p[86];sum+=p[87];
        sum+=p[88];sum+=p[89];sum+=p[90];sum+=p[91]; sum+=2.5; sum+=p[92];sum+=p[93];sum+=p[94];sum+=p[95];
        sum+=p[96];sum+=p[97];sum+=p[98];sum+=p[99]; sum+=2.5; sum+=p[100];sum+=p[101];sum+=p[102];sum+=p[103];
        sum+=p[104];sum+=p[105];sum+=p[106];sum+=p[107]; sum+=2.5; sum+=p[108];sum+=p[109];sum+=p[110];sum+=p[111];
        sum+=p[112];sum+=p[113];sum+=p[114];sum+=p[115]; sum+=2.5; sum+=p[116];sum+=p[117];sum+=p[118];sum+=p[119];
        sum+=p[120];sum+=p[121];sum+=p[122];sum+=p[123]; sum+=2.5; sum+=p[124];sum+=p[125];sum+=p[126];sum+=p[127];
        p += 128;
    }
    use_float(temp_reg);
    use_int(sum);
    return access_bytes;
}

// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_3( uint64_t access_bytes, TYPE *memory_block )
{
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        sum+=p[0];sum+=p[1];sum+=p[2];sum+=p[3]; sum+=2.5; sum+=p[4];sum+=p[5];sum+=p[6];sum+=p[7];
        sum+=p[8];sum+=p[9];sum+=p[10];sum+=p[11]; sum+=2.5; sum+=p[12];sum+=p[13];sum+=p[14];sum+=p[15]; sum+=2.5;
        sum+=p[16];sum+=p[17];sum+=p[18];sum+=p[19]; sum+=2.5; sum+=p[20];sum+=p[21];sum+=p[22];sum+=p[23];
        sum+=p[24];sum+=p[25];sum+=p[26];sum+=p[27]; sum+=2.5; sum+=p[28];sum+=p[29];sum+=p[30];sum+=p[31]; 
        sum+=p[32];sum+=p[33];sum+=p[34];sum+=p[35]; sum+=2.5; sum+=p[36];sum+=p[37];sum+=p[38];sum+=p[39]; sum+=2.5;
        sum+=p[40];sum+=p[41];sum+=p[42];sum+=p[43]; sum+=2.5; sum+=p[44];sum+=p[45];sum+=p[46];sum+=p[47];
        sum+=p[48];sum+=p[49];sum+=p[50];sum+=p[51]; sum+=2.5; sum+=p[52];sum+=p[53];sum+=p[54];sum+=p[55]; sum+=2.5;
        sum+=p[56];sum+=p[57];sum+=p[58];sum+=p[59]; sum+=2.5; sum+=p[60];sum+=p[61];sum+=p[62];sum+=p[63];
        sum+=p[64];sum+=p[65];sum+=p[66];sum+=p[67]; sum+=2.5; sum+=p[68];sum+=p[69];sum+=p[70];sum+=p[71];
        sum+=p[72];sum+=p[73];sum+=p[74];sum+=p[75]; sum+=2.5; sum+=p[76];sum+=p[77];sum+=p[78];sum+=p[79]; sum+=2.5;
        sum+=p[80];sum+=p[81];sum+=p[82];sum+=p[83]; sum+=2.5; sum+=p[84];sum+=p[85];sum+=p[86];sum+=p[87]; sum+=2.5;
        sum+=p[88];sum+=p[89];sum+=p[90];sum+=p[91]; sum+=2.5; sum+=p[92];sum+=p[93];sum+=p[94];sum+=p[95];
        sum+=p[96];sum+=p[97];sum+=p[98];sum+=p[99]; sum+=2.5; sum+=p[100];sum+=p[101];sum+=p[102];sum+=p[103];
        sum+=p[104];sum+=p[105];sum+=p[106];sum+=p[107]; sum+=2.5; sum+=p[108];sum+=p[109];sum+=p[110];sum+=p[111]; sum+=2.5;
        sum+=p[112];sum+=p[113];sum+=p[114];sum+=p[115]; sum+=2.5; sum+=p[116];sum+=p[117];sum+=p[118];sum+=p[119];
        sum+=p[120];sum+=p[121];sum+=p[122];sum+=p[123]; sum+=2.5; sum+=p[124];sum+=p[125];sum+=p[126];sum+=p[127];
        p += 128;
    }
    use_int(sum);
    return access_bytes;
}

// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_4( uint64_t access_bytes, TYPE *memory_block )
{
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        sum+=p[0];sum+=p[1];sum+=p[2];sum+=p[3]; sum+=2.5; sum+=p[4];sum+=p[5];sum+=p[6];sum+=p[7];
        sum+=p[8];sum+=p[9];sum+=p[10];sum+=p[11]; sum+=2.5; sum+=p[12];sum+=p[13];sum+=p[14];sum+=p[15]; sum+=2.5;
        sum+=p[16];sum+=p[17];sum+=p[18];sum+=p[19]; sum+=2.5; sum+=p[20];sum+=p[21];sum+=p[22];sum+=p[23]; sum+=2.5;
        sum+=p[24];sum+=p[25];sum+=p[26];sum+=p[27]; sum+=2.5; sum+=p[28];sum+=p[29];sum+=p[30];sum+=p[31]; 
        sum+=p[32];sum+=p[33];sum+=p[34];sum+=p[35]; sum+=2.5; sum+=p[36];sum+=p[37];sum+=p[38];sum+=p[39]; sum+=2.5;
        sum+=p[40];sum+=p[41];sum+=p[42];sum+=p[43]; sum+=2.5; sum+=p[44];sum+=p[45];sum+=p[46];sum+=p[47];
        sum+=p[48];sum+=p[49];sum+=p[50];sum+=p[51]; sum+=2.5; sum+=p[52];sum+=p[53];sum+=p[54];sum+=p[55]; sum+=2.5;
        sum+=p[56];sum+=p[57];sum+=p[58];sum+=p[59]; sum+=2.5; sum+=p[60];sum+=p[61];sum+=p[62];sum+=p[63];
        sum+=p[64];sum+=p[65];sum+=p[66];sum+=p[67]; sum+=2.5; sum+=p[68];sum+=p[69];sum+=p[70];sum+=p[71]; sum+=2.5;
        sum+=p[72];sum+=p[73];sum+=p[74];sum+=p[75]; sum+=2.5; sum+=p[76];sum+=p[77];sum+=p[78];sum+=p[79]; sum+=2.5;
        sum+=p[80];sum+=p[81];sum+=p[82];sum+=p[83]; sum+=2.5; sum+=p[84];sum+=p[85];sum+=p[86];sum+=p[87]; sum+=2.5;
        sum+=p[88];sum+=p[89];sum+=p[90];sum+=p[91]; sum+=2.5; sum+=p[92];sum+=p[93];sum+=p[94];sum+=p[95];
        sum+=p[96];sum+=p[97];sum+=p[98];sum+=p[99]; sum+=2.5; sum+=p[100];sum+=p[101];sum+=p[102];sum+=p[103];
        sum+=p[104];sum+=p[105];sum+=p[106];sum+=p[107]; sum+=2.5; sum+=p[108];sum+=p[109];sum+=p[110];sum+=p[111]; sum+=2.5;
        sum+=p[112];sum+=p[113];sum+=p[114];sum+=p[115]; sum+=2.5; sum+=p[116];sum+=p[117];sum+=p[118];sum+=p[119]; sum+=2.5;
        sum+=p[120];sum+=p[121];sum+=p[122];sum+=p[123]; sum+=2.5; sum+=p[124];sum+=p[125];sum+=p[126];sum+=p[127]; sum+=2.5;
        p += 128;
    }
    use_int(sum);
    return access_bytes;
}

#define DOIT(i) sum+=p[i];temp_reg+=2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_5( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127);
        p += 128;
    }
    use_float(temp_reg);
    use_int(sum);
    return access_bytes;
}
#undef DOIT

#define DOIT(i) sum+=p[i];temp_reg+=2.5;temp_reg+=2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_6( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127);
        p += 128;
    }
    use_float(temp_reg);
    use_int(sum);
    return access_bytes;
}
#undef DOIT

#define DOIT(i) sum+=p[i];temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_7( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127);
        p += 128;
    }
    use_float(temp_reg);
    use_int(sum);
    return access_bytes;
}
#undef DOIT

#define DOIT(i) sum+=p[i];temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;temp_reg+=2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t read_memory_8( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register int sum = 0;
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127);
        p += 128;
    }
    use_float(temp_reg);
    use_int(sum);
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory( uint64_t access_bytes, TYPE *memory_block )
{
    //printf("access_bytes %" PRIu64 " memory_block %p\n", access_bytes, memory_block );
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127) 1;
        p += 128;
    }
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg+2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_1( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg*2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_2( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg*2.5;temp_reg=temp_reg+2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_3( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_4( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_5( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_6( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_7( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define DOIT(i) p[i]=1;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_8( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

/*
#define SPIN_10MBS \
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\
temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;temp_reg=temp_reg*2.5;\

#define DOIT(i) p[i]=1;SPIN_10MBS
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_9( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT

#define SPIN_1MBS \
SPIN_10MBS;SPIN_10MBS;SPIN_10MBS;SPIN_10MBS;SPIN_10MBS;\
SPIN_10MBS;SPIN_10MBS;SPIN_10MBS;SPIN_10MBS;SPIN_10MBS;\

#define DOIT(i) p[i]=1;SPIN_1MBS
// access_bytes is the number of bytes to read or write
// memory_block is the start of the window to access
// returns bytes written
uint64_t write_memory_10( uint64_t access_bytes, TYPE *memory_block )
{
    register float temp_reg;
    register TYPE *lastone = memory_block;
    lastone += ( access_bytes/sizeof(TYPE) ) - 1;

    register TYPE *p = memory_block;

    // efficient write loop test
    while( p <= lastone ) {
        DOIT(0) DOIT(1) DOIT(2) DOIT(3) DOIT(4) DOIT(5) DOIT(6)
        DOIT(7) DOIT(8) DOIT(9) DOIT(10) DOIT(11) DOIT(12)
        DOIT(13) DOIT(14) DOIT(15) DOIT(16) DOIT(17) DOIT(18)
        DOIT(19) DOIT(20) DOIT(21) DOIT(22) DOIT(23) DOIT(24)
        DOIT(25) DOIT(26) DOIT(27) DOIT(28) DOIT(29) DOIT(30)
        DOIT(31) DOIT(32) DOIT(33) DOIT(34) DOIT(35) DOIT(36)
        DOIT(37) DOIT(38) DOIT(39) DOIT(40) DOIT(41) DOIT(42)
        DOIT(43) DOIT(44) DOIT(45) DOIT(46) DOIT(47) DOIT(48)
        DOIT(49) DOIT(50) DOIT(51) DOIT(52) DOIT(53) DOIT(54)
        DOIT(55) DOIT(56) DOIT(57) DOIT(58) DOIT(59) DOIT(60)
        DOIT(61) DOIT(62) DOIT(63) DOIT(64) DOIT(65) DOIT(66)
        DOIT(67) DOIT(68) DOIT(69) DOIT(70) DOIT(71) DOIT(72)
        DOIT(73) DOIT(74) DOIT(75) DOIT(76) DOIT(77) DOIT(78)
        DOIT(79) DOIT(80) DOIT(81) DOIT(82) DOIT(83) DOIT(84)
        DOIT(85) DOIT(86) DOIT(87) DOIT(88) DOIT(89) DOIT(90)
        DOIT(91) DOIT(92) DOIT(93) DOIT(94) DOIT(95) DOIT(96)
        DOIT(97) DOIT(98) DOIT(99) DOIT(100) DOIT(101) DOIT(102)
        DOIT(103) DOIT(104) DOIT(105) DOIT(106) DOIT(107)
        DOIT(108) DOIT(109) DOIT(110) DOIT(111) DOIT(112)
        DOIT(113) DOIT(114) DOIT(115) DOIT(116) DOIT(117)
        DOIT(118) DOIT(119) DOIT(120) DOIT(121) DOIT(122)
        DOIT(123) DOIT(124) DOIT(125) DOIT(126) DOIT(127)
        p += 128;
    }
    use_float( temp_reg );
    return access_bytes;
}
#undef DOIT
*/


#define BLOCK_MEMORY_READ 0
#define BLOCK_MEMORY_WRITE 1
#define BLOCK_MEMORY_XOR 2
// select which block memory access function
// read = 0, write = 1
// speed = 100, 1, 2, 3, 4, 5, 6, 7, 8
uint64_t (*get_block_memory_function( int read_write, int speed  ))( uint64_t, TYPE * )
{
    if( read_write == BLOCK_MEMORY_READ ) {
        if ( speed == 100 )
            return read_memory;
        else if ( speed == 1 )
            return read_memory_1;
        else if (speed == 2 )
            return read_memory_2;
        else if ( speed == 3 )
            return read_memory_3;
        else if (speed == 4 )
            return read_memory_4;
        else if ( speed == 5 )
            return read_memory_5;
        else if (speed == 6 )
            return read_memory_6;
        else if (speed == 7 )
            return read_memory_7;
        else if (speed == 8 )
            return read_memory_8;
    } else if( read_write == BLOCK_MEMORY_WRITE ) {
        if ( speed == 100 )
            return write_memory;
        else if ( speed == 1 )
            return write_memory_1;
        else if (speed == 2 )
            return write_memory_2;
        else if ( speed == 3 )
            return write_memory_3;
        else if (speed == 4 )
            return write_memory_4;
        else if ( speed == 5 )
            return write_memory_5;
        else if (speed == 6 )
            return write_memory_6;
        else if (speed == 7 )
            return write_memory_7;
        else if (speed == 8 )
            return write_memory_8;
    }
    return 0;
}

#endif //BLOCK_MEMORY_FUNCTIONS_H_
