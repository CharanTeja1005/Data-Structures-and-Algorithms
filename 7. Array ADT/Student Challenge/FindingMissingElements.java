public class FindingMissingElements {
    public static void findMissingElement(int A[])
    {
        int l = min(A);
        int h = max(A);
        int H[] = new int[h+1];
        for(int i=0;i<A.length;i++)
        {
            H[A[i]]++;
        }
        for(int i=l;i<=h;i++)
        {
            if(H[i] == 0)
                System.out.println("Missing Element : " + i);
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

    public static void main(String[] args) {
        int arr2[] = new int[] {10,6,11,12,7,15,8,20}; // 9 13 14 16 17 18 19
        findMissingElement(arr2);
    }
}
