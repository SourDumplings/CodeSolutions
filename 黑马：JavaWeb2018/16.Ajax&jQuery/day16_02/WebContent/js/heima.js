// 在文档准备就绪的时候对某一个元素进行onkeyup事件监听
/* $(document).ready(function()
{
    // 与下面一行等价
}); */
$(function ()
{
    // 1.捕捉到键盘弹起的事件
    $("#word").keyup(function ()
    {
        // alert("键盘弹起了");

        // 2.获取输入框的值
        // var word = $("#word").val(); 与下一行等价
        var word = $(this).val();

        if (word == "")
        {
            $("#div01").hide();
        }
        else
        {
            // 3.请求数据
            $.post("/day16_02/FindWordsServlet", { word: word }, function (data, status)
            {
                // alert(data);
                $("#div01").show();
                $("#div01").html(data);
            });
        }

    });
});




