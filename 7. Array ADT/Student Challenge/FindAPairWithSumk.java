public class FindAPairWithSumk {
    public static void pairWithSumk(int a[],int k)
    {
        for(int i=0;i<a.length;i++)
        {
            for(int j=i+1;j<a.length;j++)
            {
                if(a[i] + a[j] == k)
                    System.out.println(a[i] + " + " + a[j] + " = " + k);
            }
        }
    }

    public static int max(int a[])
    {
        int max = a[0];
        for(int i=0;i<a.length;i++)
        {
            if(a[i] > max)
                max = a[i];
        }
        return max;
    }

    public static void pairWithSumkUsingHashing(int A[],int k)
    {
        int h = max(A);
        int H[] = new int[h+1];
        for(int i=0;i<A.length;i++)
        {
            if(k-A[i] >=0 && H[k - A[i]] != 0)
                System.out.println(A[i] + " + " + (k-A[i]) + " = " + k);
            H[A[i]]++;
        }
    }
    public static void main(String[] args) {
        int arr[] = new int[]{6,3,8,10,16,7,3,2,9,14};
        System.out.println("Finding a pair with sum k :");
        pairWithSumk(arr, 10);
        System.out.println("Finding a pair with sum k using Hashing:");
        pairWithSumkUsingHashing(arr, 10);
    }
}
