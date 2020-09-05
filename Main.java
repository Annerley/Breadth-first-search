package com.company;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String[] args)
    {
        //System.out.println("Hello World!");
        Deque<Integer> q = new LinkedList<Integer>();
        int N = 5;
        int[][] matrixA = {
                {0, 1, 0, 0, 1},
                {1, 0, 1, 0, 0},
                {0, 1, 0, 0, 0},
                {0, 0, 0, 0, 0},
                {1, 0, 0, 0, 0}
        };
        int start = 3;
        int end = 5;
        int lenght[] = new int[N];
        for (int i = 0; i < N; i++)
        {
            lenght[i] = -1;
        }
        q.offerLast(start - 1);


        lenght[start - 1] = 0;

        while (q.peekFirst()==null)
        {
            int i = q.getFirst();
            q.removeFirst();

            for (int j = 0; j < N; j++)
            {
                if (matrixA[i][j] == 1)
                {
                    if (lenght[j] == -1 && i != j)
                    {
                        q.offerLast(j);
                        lenght[q.getLast()] = lenght[i] + 1;
                    }

                }
            }
        }
        if (start == end) lenght[end - 1] = 0;

        System.out.println(lenght[end - 1]);






    }
}
