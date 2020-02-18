package com.cz.hello.email;

import org.apache.commons.mail.DefaultAuthenticator;
import org.apache.commons.mail.Email;
import org.apache.commons.mail.EmailException;
import org.apache.commons.mail.SimpleEmail;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-email
 * @date 2020/2/17 21:57
 */
public class MyTest
{
    public static void main(String[] args) throws EmailException
    {
        Email email = new SimpleEmail();
        email.setHostName("smtp.163.com");
        email.setSmtpPort(465);
        email.setAuthenticator(new DefaultAuthenticator("sourdumplings@163.com", "123456"));
        email.setSSLOnConnect(true);
        email.setFrom("sourdumplings@163.com");
        email.setSubject("TestMail");
        email.setMsg("This is a test mail ... :-)");
        email.addTo("changzheng300@foxmail.com");
        email.send();
    }

}
