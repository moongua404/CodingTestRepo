import java.util.*;
import java.util.stream.*;

class Node {
    int minV;
    List<Node> nexts;

    Node() {
        minV = 0x7FFFFFFF;
        nexts = new ArrayList<>();
    }
}

class Solution {
    public int solution(int n, int[][] edge) {
        Map<Integer, Node> maps = new HashMap<>();
        IntStream.range(0, n)
                .forEach((i) -> maps.put(i+1, new Node()));

        for (int[] e : edge) {
            maps.get(e[0]).nexts.add(maps.get(e[1]));
            maps.get(e[1]).nexts.add(maps.get(e[0]));
        }
        maps.get(1).minV = 0;

        Queue<Node> q = new ArrayDeque<>();
        q.add(maps.get(1));
        while(!q.isEmpty()) {
            Node node = q.peek();
            q.remove();

            node.nexts.forEach(next -> {
                if (next.minV > node.minV+1) {
                    next.minV = node.minV+1;
                    q.add(next);
                }
            });
        }

        int max = maps.values().stream().map(v -> v.minV).max(Integer::compare).get();
        int answer = (int) maps.values().stream().filter(v -> v.minV == max).count();
        return answer;
    }
}