$(function ()
{
    // 1.找到省份的元素
    $("#province").change(function ()
    {
        // alert("省份改变了！");
        // 2.一旦里面的值发生了改变，就去请求该省份的城市数据
        var pid = $(this).val();
        $.post("CityServlet02", { pid: pid }, function (data, status)
        {
        	// alert("有数据回来：" + data);
            // 回来的数据格式
            /* [
                {
                    "cid": 1,
                    "cname": "广州",
                    "pid": 1
                },
                {
                    "cid": 2,
                    "cname": "东莞",
                    "pid": 1
                },...
            ] */
            // 先清空以前的值
            $("#cities").html("<option value=''>-请选择-");
            // 遍历
            $(data).each(function (index, city)
            {
                $("#cities").append("<option value='" + city.cid + "'>" + city.cname);

            });
        }, "json");
    });

    // 3.
});