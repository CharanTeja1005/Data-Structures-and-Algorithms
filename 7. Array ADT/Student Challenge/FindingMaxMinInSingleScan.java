public class FindingMaxMinInSingleScan {
    public static void main(String[] args) {
        int A[] = new int[]{5,8,3,9,6,2,10,7,-1,4};
        int min = A[0];
        int max = A[0];
        for(int i=1;i<A.length;i++)
        {
            if(A[i] < min)
                min = A[i];
            else if(A[i] > max)
                max = A[i];
        }
        System.out.println("Minimum Element : " + min);
        System.out.println("Maximum ELement : " + max);
    }
}
