public class FindingDuplicatesInSorted {
    public static void findDuplicatesInSorted(int A[])
    {
        for(int i=0;i<A.length-1;i++)
        {
            if(A[i] == A[i+1])
            {
                int j = i + 1;
                while(A[i] == A[j]) j++;
                System.out.println(A[i] + " is appearing " + (j-i) + " times");
                i = j - 1;
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

    public static void findDuplicatesInSortedUsingHashing(int A[])
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
        int arr[] = new int[] {6,6,6,9,9,10,11,12,12,12,12,14,14,15};
        System.out.println("Finding Duplicate elements in sorted array :");
        findDuplicatesInSorted(arr);
        System.out.println("Finding Duplicate elements in sorted array using Hashing :");
        findDuplicatesInSortedUsingHashing(arr);
    }
}
