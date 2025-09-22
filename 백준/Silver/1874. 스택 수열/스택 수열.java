import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        mainLogic(br, bw);
        br.close();
        bw.close();
    }

    private static void mainLogic(BufferedReader br, BufferedWriter bw) throws IOException {
        Stack<Integer> stack = new Stack<>();

        int nums = Integer.parseInt(br.readLine());
        int current = 0;
        StringBuilder output = new StringBuilder();

        try {
            for (int num = 1; num <= nums; num++) {
                int pick = Integer.parseInt(br.readLine());
                while(current < pick) {
                    output.append("+\n");
                    current++;
                    stack.push(current);
                }
                output.append("-\n");
                int v = stack.pop();
                if (v != pick) {
                    throw new RuntimeException();
                }
            }
            bw.write(output.toString());
        } catch (RuntimeException e) {
            bw.write("NO");
        } finally {
            bw.flush();
        }
    }
}
