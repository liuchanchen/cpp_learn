#!/bin/bash
# sed -i "412,475s/+ 0)/+ 4)/g" opt_gmem.h
# sed -i "412,475s/\[0\]\[/[4][/g" opt_gmem.h
# sed -i "476,539s/+ 1)/+ 5)/g" opt_gmem.h
# sed -i "476,539s/\[1\]\[/[5][/g" opt_gmem.h
# sed -i "540,603s/+ 2)/+ 6)/g" opt_gmem.h
# sed -i "540,603s/\[2\]\[/[6][/g" opt_gmem.h
# sed -i "604,667s/+ 3)/+ 7)/g" opt_gmem.h
# sed -i "604,667s/\[3\]\[/[7][/g" opt_gmem.h
sed -i "720,783s/k \* N + n/kN_0_k/g" opt_gmem.h
sed -i "720,783s/(k + 1) \* N + n/kN_1_k/g" opt_gmem.h
sed -i "720,783s/(k + 2) \* N + n/kN_2_k/g" opt_gmem.h
sed -i "720,783s/(k + 3) \* N + n/kN_3_k/g" opt_gmem.h
sed -i "720,783s/m \* K + n/mK_0_n/g" opt_gmem.h
sed -i "720,783s/(m + 1) \* K + n/mK_1_n/g" opt_gmem.h
sed -i "720,783s/(m + 2) \* K + n/mK_2_n/g" opt_gmem.h
sed -i "720,783s/(m + 3) \* K + n/mK_3_n/g" opt_gmem.h
