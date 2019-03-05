$(function ()
{
    // 1.找到省份的元素
    $("#province").change(function ()
    {
        // alert("省份改变了！");
        // 2.一旦里面的值发生了改变，就去请求该省份的城市数据
        var pid = $(this).val();
        $.post("CityServlet", { pid: pid }, function (data, status)
        {
            // alert("回来数据了：" + data);
            /*          回来的数据格式：   
                        <list>
                            <city>
                                <cid>1</cid>
                                <cname>广州</cname>
                                <pid>1</pid>
                            </city>
                            <city>
                                <cid>2</cid>
                                <cname>东莞</cname>
                                <pid>1</pid>
                            </city>
                        </list> */

            // 先清空以前的值
            $("#cities").html("<option value=''>-请选择-");
            // 遍历
            // 从data数据里面找出所有的city，然后遍历所有的city
            // 遍历一个city，就执行一个function方法
            $(data).find("city").each(function ()
            {
                var cid = $(this).children("cid").text();
                var cname = $(this).children("cname").text();

                // alert("cid:" + cid + ", cname:" + cname);

                $("#cities").append("<option value='" + cid + "'>" + cname);

            });

        });
    });

    // 3.
});