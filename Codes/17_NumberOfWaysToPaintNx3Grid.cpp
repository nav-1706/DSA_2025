class Solution {
public:

    // https://youtu.be/uId0P2zAHKk?si=NearR8GdgcX_UEvE

    int MOD = 1000000007;

    int numOfWays(int n) {

        long long int two_color = 6; // for 1st rows, 2 color combination painting is of total 6
        long long int three_color = 6;

        for(int i=2; i<=n; i++){ // from 2nd row to nth row

            long long int temp = two_color;

            two_color = ( (two_color*3 + three_color*2))%MOD;
            three_color = ((temp*2 + three_color*2))%MOD;
        }

        return (two_color + three_color)%MOD;
    }
};