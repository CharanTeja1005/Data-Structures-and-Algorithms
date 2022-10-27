public class FindingDuplicatesInUnsorted {
    public static void findDuplicatesInUnsorted(int A[])
    {
        for(int i=0;i<A.length-1;i++)
        {
            int count = 1;
            if(A[i] != -1)
            {
                for(int j=i+1;j<A.length;j++)
                {
                    if(A[i] == A[j])
                    {
                        count++;
                        A[j] = -1;
                    }
                }
                if(count > 1)
                    System.out.println(A[i] + " is appearing " + count + " times");
            }
        }
    }

    public static int min(int a[])
    {
        int min = a[0];
        for(int i=0;i<a.length;i++)
        {
            if(a[i] < min)
                min = a[i];
        }
        return min;
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

    public static void findDuplicatesInUnsortedUsingHashing(int A[])
    {
        int l = min(A);
        int h = max(A);
        int H[] = new int[h+1];
        for(int i=0;i<A.length;i++)
            H[A[i]]++;
        for(int i=l;i<=h;i++)
            if(H[i] > 1)
                System.out.println(i + " is appearing " + H[i] + " times");
    }

    public static void main(String[] args) {
        int arr[] = new int[] {8,3,6,4,6,5,6,8,2,7};
        System.out.println("Finding Duplicate elements in unsorted array using Hashing :");
        findDuplicatesInUnsortedUsingHashing(arr);
        System.out.println("Finding Duplicate elements in unsorted array :");
        findDuplicatesInUnsorted(arr);
    }
}
