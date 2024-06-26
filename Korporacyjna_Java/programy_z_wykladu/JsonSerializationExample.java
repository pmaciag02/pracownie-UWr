package corporate.java;

/*
    <dependencies>
        <dependency>
            <groupId>com.fasterxml.jackson.core</groupId>
            <artifactId>jackson-databind</artifactId>
            <version>2.15.0</version>
        </dependency>
        <dependency>
            <groupId>com.google.code.gson</groupId>
            <artifactId>gson</artifactId>
            <version>2.10.1</version>
        </dependency>
    </dependencies>
 */

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.google.gson.Gson;

public class JsonSerializationExample {

    private static Person getSamplePerson() {
        return new Person("Stefan", "Nowak", 55, "Developer");
    }

    private static String getSamplePersonJson() {
        return "{\"name\":\"Stefan\",\"lastName\":\"Nowak\",\"age\":55,\"position\":\"Developer\"}";
    }

    private static Person getSamplePerson2() {
        return new Person("Stefan", "Nowak", 55, null);
    }

    private static String getSamplePersonJson2() {
        return "{\"name\":\"Stefan\",\"lastName\":\"Nowak\",\"age\":55,\"position\":null}";
    }

    public static void main(String[] args) {
//        jacksonExample();
//        gsonExample();
//        jacksonExample2();
//        gsonExample2();
    }

    private static void jacksonExample() {
        try {
            Person person = getSamplePerson();
            ObjectMapper mapper = new ObjectMapper();
            System.out.println(mapper.writeValueAsString(person));
            Person personFromJson = mapper.readValue(getSamplePersonJson(), Person.class);
            System.out.println(person.equals(personFromJson));
        } catch (JsonProcessingException exception) {
            throw new RuntimeException("CAN'T PARSE DUE TO: " + exception.getMessage());
        }
    }

    private static void gsonExample() {
        Person person = getSamplePerson();
        Gson gson = new Gson();
        System.out.println(gson.toJson(person));
        Person personFromJson = gson.fromJson(getSamplePersonJson(), Person.class);
        System.out.println(person.equals(personFromJson));
    }

    private static void jacksonExample2() {
        try {
            Person person = getSamplePerson2();
            ObjectMapper mapper = new ObjectMapper();
            System.out.println(mapper.writeValueAsString(person));
            Person personFromJson = mapper.readValue(getSamplePersonJson2(), Person.class);
            System.out.println(person.equals(personFromJson));
        } catch (JsonProcessingException exception) {
            throw new RuntimeException("CAN'T PARSE DUE TO: " + exception.getMessage());
        }
    }

    private static void gsonExample2() {
        Person person = getSamplePerson2();
        Gson gson = new Gson();
        System.out.println(gson.toJson(person));
        Person personFromJson = gson.fromJson(getSamplePersonJson2(), Person.class);
        System.out.println(person.equals(personFromJson));
    }
}
