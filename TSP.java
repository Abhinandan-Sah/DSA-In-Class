public class TSP {
    static int n;
    static int[][] dist;
    static int[][] dp;

    public static int findMinCostPath(int mask, int pos){
        if(mask == (1 << n) -1){
            return dist[pos][0];
        }

        if(dp[mask][pos] != -1){
            return dp[mask][pos];
        }
        int ans = Integer.MAX_VALUE;
        for(int city = 0; city < n; city++){
            if((mask & (1 << city)) == 0){
                int newAns = dist[pos][city] + findMinCostPath(mask | (1 << city), city);
                ans = Math.min(ans, newAns);
            }
        }
        return dp[mask][pos] = ans;
    }

    public static void main(String[] arg){
        n=4;
        dist = new int[][]{
            {0, 1, 15, 6}, 
            {2, 0, 7, 3}, 
            {9, 6, 0, 12}, 
            {10, 4, 8, 0}
        };
        dp = new int[1 << n][n];
        for(int i = 0; i < (1 << n); i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = -1;
            }
        }
        int minCost = findMinCostPath(1, 0);
        System.out.println("Minimum cost of visiting all cities: " + minCost);
    
    }
}
