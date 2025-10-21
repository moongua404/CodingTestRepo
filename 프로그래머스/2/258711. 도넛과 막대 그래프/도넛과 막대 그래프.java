import java.util.*;
import java.util.stream.*;

class Solution {
    public int[] solution(int[][] edges) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        List<Integer> startCandidates = new LinkedList<>();

        for (int[] edge : edges) {
            if (map.get(edge[0]) == null) {
                map.put(edge[0], new ArrayList<>());
            } else {
                startCandidates.add(edge[0]);
            }
            map.get(edge[0]).add(edge[1]);
        }

        int start = startCandidates.stream()
                .filter(v -> map.values().stream().noneMatch(l -> l.contains(v)))
                .findAny().get();

        int donut = 0;
        int pole = 0;
        int eight = 0;

        for (int graphStart : map.get(start)) {
            int cur = graphStart;
            while(true) {
                List<Integer> nexts = map.get(cur);
                if (nexts == null) {
                    pole++;
                    break;
                } else if (nexts.size() >= 2) {
                    eight++;
                    break;
                } else if (nexts.get(0) == graphStart) {
                    donut++;
                    break;
                }
                cur = nexts.get(0);
            }
        }

        int[] answer = {start, donut, pole, eight};
        return answer;
    }
}

/*
Insights
- 주는게 2개 이상이되 받는게 없다면 start
    - 주는게 2개가 될 수 있는것은 start(2개 이상)와 8자에서 중간 부분(2개)
    - 8자에서 중간 부분은 반드시 주는게 (2개) 있음
- 막대 : 선형적으로 주는 것만 있음
- 도넛 : 막대의 마지막 점에서 시작점으로 loop가 형성됨
- 8자 : 도넛의 한 점이 다른 도넛의 한 점을 구성함
*/