public class FindingSingleMissingElement {
    public static void singleMissingElement(int arr[])
    {
        int sum = 0;
        int n = arr.length;
        for(int i=0;i<n;i++)
            sum += arr[i];
        int s = arr[n-1]*(arr[n-1]+1)/2;
        int sme = s - sum;
        if(sme == 0)
            System.out.println("No element is missing");
        else
            System.out.println("Missing element : " + sme);
    }
    public static void findSingleMissingElement(int arr[])
    {
        int n = arr.length;
        int diff = arr[0] - 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] - i != diff)
            {
                System.out.println("Missing element : " + (i+diff));
                return;
            }
        }
        System.out.println("No element is missing");
    }
    public static void main(String[] args) {
        int arr[] = new int[] {1,2,3,4,5,6,8,9,10,11,12}; //7
        singleMissingElement(arr);
        int arr2[] = new int[] {6,7,8,9,10,11,12,20}; //13
        findSingleMissingElement(arr2);
    }
}
