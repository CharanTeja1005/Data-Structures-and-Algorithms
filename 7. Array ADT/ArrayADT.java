import java.io.*;

class Array{
    int A[];
    int size;
    int length;
    Array()
    {
        this.length = 0;
    }
}

public class ArrayADT
{
    public static void append(Array a,int x)
    {
        if(a.length < a.size)
        {
            a.A[a.length++] = x;
        }
    }
    
    public static void insert(Array a,int index,int x)
    {
        if(index >= 0 && index <= a.length)
        {
            for(int i=a.length;i>index;i--)
            {
                a.A[i] = a.A[i-1];
            }
            a.A[index] = x;
            a.length++;
        }
    }

    public static int delete(Array a,int index)
    {
        if(index >= 0 && index < a.length)
        {
            int x = a.A[index];
            for(int i=index;i<a.length-1;i++)
            {
                a.A[i] = a.A[i+1];
            }
            a.length--;
            return x;
        }
        return -1;
    }

    public static int search(Array a,int key)
    {
        for(int i=0;i<a.length;i++)
        {
            if(key == a.A[i])
                return i;
        }
        return -1;
    }

    public static void display(Array a)
    {
        for(int i=0;i<a.length;i++)
        {
            System.out.print(a.A[i] + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Array arr = new Array();
        int choice = 0;
        int x,index;

        System.out.print("Enter the size of Array : ");
        arr.size = Integer.parseInt(br.readLine());
        arr.A = new int[arr.size];
        while(choice < 11)
        {
            System.out.println("\nQueue Main Menu:\n");
            System.out.println("1. Append\n2. Insert\n3. Delete\n4. Search\n5. Display\n6. Exit\n");
            System.out.print("Choose one option : ");
            choice = Integer.parseInt(br.readLine());
            switch(choice)
            {
                case 1: System.out.print("\nEnter the element to be appended : ");
                        x = Integer.parseInt(br.readLine());
                        append(arr,x);
                        break;
                case 2: System.out.print("\nEnter the index to be inserted : ");
                        index = Integer.parseInt(br.readLine());
                        System.out.print("\nEnter the element to be inserted : ");
                        x = Integer.parseInt(br.readLine());
                        insert(arr,index,x);
                        break;
                case 3: System.out.print("\nEnter the index to be deleted : ");
                        index = Integer.parseInt(br.readLine());
                        System.out.println("Deleted element : " + delete(arr, index));
                        break;
                case 4: System.out.print("\nEnter the element to be searched : ");
                        x = Integer.parseInt(br.readLine());
                        int s = search(arr, x);
                        System.out.println((s == -1) ? "\nElement not found in Array" : "\nElement found at index : " + s);
                        break;
                case 5: System.out.print("\nThe elements of Array ADT are : ");
                        display(arr);
                        break;
                case 6: System.out.println("\nProgram Terminated");
                        System.exit(0);
               default: System.out.println("\nIncorrect choice, try again");
                        break;
            }
        }
    }
}