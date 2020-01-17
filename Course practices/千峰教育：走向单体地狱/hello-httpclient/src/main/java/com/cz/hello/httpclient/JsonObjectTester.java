package com.cz.hello.httpclient;

import com.fasterxml.jackson.core.JsonParseException;
import com.fasterxml.jackson.databind.JsonMappingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.IOException;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-httpclient
 * @date 2020/1/17 21:53
 */
public class JsonObjectTester
{
    public static void main(String[] args)
    {
        // 创建 ObjectMapper 对象
        ObjectMapper mapper = new ObjectMapper();
        String jsonString = "{\"name\":\"Mahesh\", \"age\":21}";

        try
        {
            // 反序列化 JSON 到对象
            Student student = mapper.readValue(jsonString, Student.class);
            System.out.println(student);

            // 序列化对象到 JSON
            String json = mapper.writeValueAsString(student);
            System.out.println(json);
        }
        catch (JsonParseException e)
        {
            e.printStackTrace();
        }
        catch (JsonMappingException e)
        {
            e.printStackTrace();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}

class Student
{
    private String name;
    private int age;

    public Student()
    {
    }

    public String getName()
    {
        return name;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public int getAge()
    {
        return age;
    }

    public void setAge(int age)
    {
        this.age = age;
    }

    @Override
    public String toString()
    {
        return "Student [ name: " + name + ", age: " + age + " ]";
    }
}