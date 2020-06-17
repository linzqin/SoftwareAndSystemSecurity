<?php
$name=$_POST["user"];//POST获取用户输入的user内容
$pwd=$_POST["pwd"];
$mail=$_POST["mail"];
if($name=="admin"&&$pwd=="123"){
	
	echo "登录成功";
	
}
else if($name=="admin"||$pwd=="123")
{
	echo "账号或密码错误，请重试";
	
}
else{
	
	echo "登录失败，无法验证您的身份，谢谢合作！";
}