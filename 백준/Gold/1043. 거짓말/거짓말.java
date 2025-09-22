import java.io.*;
import java.util.*;
import java.util.stream.IntStream;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        mainLogic(sc, bw);
        bw.close();
    }

    private static int getInt(Scanner sc) throws IOException {
        return sc.nextInt();
    }

    private static void mainLogic(Scanner sc, BufferedWriter bw) throws IOException {
        PartyManager partyManager = new PartyManager(getInt(sc));
        int numOfParties = getInt(sc);
        int numOfAware = getInt(sc);
        for (int i = 0; i < numOfAware; i++) {
            Person target = partyManager.personList.get(getInt(sc) - 1);
            target.awareness = true;
            partyManager.awarenessVirus.add(target);
        }

        for (int i = 0; i < numOfParties; i++) {
            int numOfParticipants = getInt(sc);
            Party party = new Party();
            for (int j = 0; j < numOfParticipants; j++) {
                Person participant = partyManager.personList.get(getInt(sc) - 1);
                party.Participants.add(participant);
                participant.participatedParties.add(party);
            }
            partyManager.partyList.add(party);
        }

        partyManager.spread();

        long result = partyManager.partyList.stream().filter(party -> !party.alreadySpread)
                .count();

        bw.write(result + "\n");
    }
}

class PartyManager {
    Queue<Person> awarenessVirus;
    List<Person> personList;
    List<Party> partyList;

    PartyManager(int countOfPeople) {
        awarenessVirus = new ArrayDeque<>();
        personList = new ArrayList<>(countOfPeople);
        partyList = new ArrayList<>();

        IntStream.range(0, countOfPeople).forEach(ignored -> personList.add(new Person()));
    }

    void spread() {
        while(!awarenessVirus.isEmpty()) {
            Person person = awarenessVirus.remove();
            person.participatedParties.forEach(party -> {
                if (!party.alreadySpread) {
                    party.alreadySpread = true;
                    party.Participants.forEach(participant -> {
                        if (!participant.awareness) {
                            participant.awareness = true;
                            awarenessVirus.add(participant);
                        }
                    });
                }
            });
        }
    }
}

class Person {
    boolean awareness;
    List<Party> participatedParties;

    Person() {
        awareness = false;
        participatedParties = new ArrayList<>();
    }
}

class Party {
    boolean alreadySpread;
    List<Person> Participants;

    Party() {
        alreadySpread = false;
        Participants = new ArrayList<>();
    }
}
