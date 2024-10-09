class Solution {
    public double trimMean(int[] arr) {
        Arrays.sort(arr);
        int n=arr.length;
        int a=n*5/100;
        int sum=0;
        for (int i=a;i<n-a;i++) {
            sum = sum+arr[i];
        }
        return (double)sum/(n - 2 * a);
    }
}