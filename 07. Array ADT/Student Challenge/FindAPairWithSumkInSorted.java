public class FindAPairWithSumkInSorted {
    public static void pairWithSumkInSorted(int a[],int k)
    {
        int i = 0;
        int j = a.length - 1;
        while(i < j)
        {
            if(a[i] + a[j] == k)
            {
                System.out.println(a[i] + " + " + (k-a[i]) + " = " + k);
                i++;
                j--;
            }
            else if(a[i] + a[j] < k)
                i++;
            else
                j--;
        }
    }
    
    public static void main(String[] args) {
        int arr[] = new int[]{1,3,4,5,6,8,9,10,12,14};
        System.out.println("Finding a pair with sum k :");
        pairWithSumkInSorted(arr, 10);
    }
}
