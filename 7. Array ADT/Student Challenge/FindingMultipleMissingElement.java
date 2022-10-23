public class FindingMultipleMissingElement {
    public static void findMultipleMissingElement(int arr[])
    {
        int n = arr.length;
        int diff = arr[0] - 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i] - i != diff)
            {
                while(arr[i] - i != diff)
                {
                    System.out.println("Missing element : " + (i + diff));
                    diff++;
                }
            }
        }
    }

    public static void main(String[] args) {
        int arr2[] = new int[] {6,7,8,9,10,11,12,15,20}; // 13 14 16 17 18 19
        findMultipleMissingElement(arr2);
    }
}
