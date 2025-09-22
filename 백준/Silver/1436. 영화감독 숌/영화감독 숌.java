import static java.lang.Math.pow;

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
        Set<Integer> candidates = new HashSet<>();

        int count = 0;
        int target = Integer.parseInt(br.readLine());

        int round = -1;

        while(count <= target) {
            round++;

            for (int pos = 0; pos <= round; pos++) {
                int leftPow = (int) pow(10, pos);
                int rightPow = (int) pow(10, round - pos);

                for (int i = 0; i < leftPow; i++) {
                    for (int j = 0; j < rightPow; j++) {
                        if (tryPut(candidates, i * 1000 * rightPow + 666 * rightPow + j)) {
                            count++;
                        }
                    }
                }
            }
        }

        bw.write(String.valueOf(candidates.stream().sorted().toArray()[target-1]));
    }

    private static boolean tryPut(Set<Integer> set, int v) {
        if (set.contains(v)) {
            return false;
        }
        set.add(v);
        return true;
    }
}
