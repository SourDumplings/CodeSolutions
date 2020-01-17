package com.cz.hello.httpclient;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.JavaType;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author CHANG Zheng
 * @version 1.0.0
 * @projectName hello-httpclient
 * @date 2020/1/17 22:26
 */
public class JsonListTester
{
    public static void main(String[] args)
    {
        // 创建 ObjectMapper 对象
        ObjectMapper mapper = new ObjectMapper();
        String jsonString = "{\"draw\":1,\"recordsTotal\":1,\"recordsFiltered\":1,\"data\":[{\"id\":34,\"title\":\"ad1\",\"subTitle\":\"ad1\",\"titleDesc\":\"ad1\",\"url\":\"https://sale.jd.com/act/XkCzhoisOMSW.html\",\"pic\":\"https://m.360buyimg.com/babel/jfs/t20164/187/1771326168/92964/b42fade7/5b359ab2N93be3a65.jpg\",\"pic2\":\"\",\"content\":\"<p><br></p>\"}, {\"id\":35,\"title\":\"ad1\",\"subTitle\":\"ad1\",\"titleDesc\":\"ad1\",\"url\":\"https://sale.jd.com/act/XkCzhoisOMSW.html\",\"pic\":\"https://m.360buyimg.com/babel/jfs/t20164/187/1771326168/92964/b42fade7/5b359ab2N93be3a65.jpg\",\"pic2\":\"\",\"content\":\"<p><br></p>\"}],\"error\":null}";

        try
        {
            // 反序列化 JSON 到树
            JsonNode jsonNode = mapper.readTree(jsonString);

            // 从树中读取 data 节点
            JsonNode jsonData = jsonNode.findPath("data");
            System.out.println(jsonData);

            // 反序列化 JSON 到集合
            // 方法1：使用 JavaType
/*            JavaType javaType = mapper.getTypeFactory()
                .constructParametricType(ArrayList.class, TbContent.class);
            List<TbContent> tbContents = mapper.readValue(jsonData.toString(), javaType);*/
            // 方法2：使用 TypeReference
            List<TbContent> tbContents = mapper
                .readValue(jsonData.toString(), new TypeReference<List<TbContent>>()
                {
                });

            for (TbContent tbContent : tbContents)
            {
                System.out.println(tbContent);
            }

            // 序列化集合到 JSON
            String json = mapper.writeValueAsString(tbContents);
            System.out.println(json);
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}

class TbContent
{
    private Long id;
    private String title;
    private String subTitle;
    private String titleDesc;
    private String url;
    private String pic;
    private String pic2;
    private String content;

    public Long getId()
    {
        return id;
    }

    public void setId(Long id)
    {
        this.id = id;
    }

    public String getTitle()
    {
        return title;
    }

    public void setTitle(String title)
    {
        this.title = title;
    }

    public String getSubTitle()
    {
        return subTitle;
    }

    public void setSubTitle(String subTitle)
    {
        this.subTitle = subTitle;
    }

    public String getTitleDesc()
    {
        return titleDesc;
    }

    public void setTitleDesc(String titleDesc)
    {
        this.titleDesc = titleDesc;
    }

    public String getUrl()
    {
        return url;
    }

    public void setUrl(String url)
    {
        this.url = url;
    }

    public String getPic()
    {
        return pic;
    }

    public void setPic(String pic)
    {
        this.pic = pic;
    }

    public String getPic2()
    {
        return pic2;
    }

    public void setPic2(String pic2)
    {
        this.pic2 = pic2;
    }

    public String getContent()
    {
        return content;
    }

    public void setContent(String content)
    {
        this.content = content;
    }

    @Override
    public String toString()
    {
        return "TbContent{" +
            "id=" + id +
            ", title='" + title + '\'' +
            ", subTitle='" + subTitle + '\'' +
            ", titleDesc='" + titleDesc + '\'' +
            ", url='" + url + '\'' +
            ", pic='" + pic + '\'' +
            ", pic2='" + pic2 + '\'' +
            ", content='" + content + '\'' +
            '}';
    }
}
