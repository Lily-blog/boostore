import java.util.*;


public class Main {
    public static int getMaxValue(int[] weight, int[] value, int w, int n) {
      // 创建一个二维数组，横列是物品的价值，竖列是物品的重量
        int[][] table = new int[n + 1][w + 1];
        for (int i = 1; i <= n; i++) { //物品
            for (int j = 1; j <= w; j++) {  //背包大小
                if (weight[i] > j) {
                    //当前物品i的重量比背包容量j大，装不下，肯定就是不装
                    table[i][j] = table[i - 1][j];
                } else {
                  //装得下，Max{装物品i， 不装物品i}
                    table[i][j] = Math.max(table[i - 1][j], table[i - 1][j - weight[i]] + value[i]);
                }
            }
        }
        return table[n][w];
    }

    public static void main(String[] args) {
        int n = 5, w = 13;                //物品个数，背包容量
        int[] value = {0,9,10,9,2,24};    //各个物品的价值
        int[] weight = {0,4,5,4,3,10};    //各个物品的重量
        System.out.println(getMaxValue(weight, value, w, n));
    }
}