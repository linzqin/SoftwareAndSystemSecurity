# XSS攻击
## 实验背景
* Windows主机
## 实验完成度
* [x] 完成XSS攻击
## 实验过程
### 最简单的XSS攻击
1. 延用上学期的实验，用apache服务器和php来完成的                 
2. 在`D:\wamp\Apache24\htdocs`中的`1.html`
```html
<html>
<body>
<form method="post">
        <input type="text">
        <button>提交</button>
      </form>
</body>
</html>
```
3. `D:\wamp\Apache24\htdocs`下的action.php
```php
<?php
    echo "Hello Worls!";
    echo "<br>当前时间为：".date("Y-m-d H:i:s");
    $name=$_POST["name"]; 
    echo $name;  
?>
```  
4. `localhost://1.html`访问后，在对话框里输入`<script>alert('hack')</script>`              
![](./img/ok.png)                 
![](./img/after.png)               
