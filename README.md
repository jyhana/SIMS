<!--
 * @Description: 
 * @Version: 2.0
 * @Autor: JYHan
 * @Date: 2021-07-06 15:23:18
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-07-06 16:11:50
-->
# SIMS
## 新手第一次提交代码<br/>
在github里新建一个仓库（repository), 如果是第一次使用git，就需要连接你的github账号<br/>
`git config --global user.name "@@@" `    (GitHub相对应的帐号名称)<br/>
`git config --global user.email "123@163.com" ` （GitHbu相对应的邮箱帐号）<br/>

然后cd到你的代码文件夹下面，依次执行：<br/>
`git init`<br/>
`git remote add origin http:`<br/>
`git add .`<br/>
`git commit -m "备注信息"`<br/>
`git push -u origin --all`<br/>

以后每次想提交代码的时候就可以想查询状态：<br/>
`git status`<br/>
然后查看需要提交的东西：<br/>
`git add .`<br/>
输入提交信息<br/><br/>
`git commit -m "XX"`<br/>
push到master<br/>
`git push origin master`<br/>
pull到master<br/>
`git pull origin master`<br/>

#常用命令<br/>
下载仓库：`$ git clone git://github.com/jquery/jquery.git`<br/>
查看远程仓库：`$ git remote -v`<br/>
添加远程仓库：`$ git remote add [name] [url]`<br/>
删除远程仓库：`$ git remote rm [name]`<br/>
修改远程仓库：`$ git remote set-url --push [name] [newUrl]`<br/>
拉取远程仓库：`$ git pull [remoteName] [localBranchName]`<br/>
推送远程仓库：`$ git push [remoteName] [localBranchName]`<br/>

如果想把本地的某个分支test提交到远程仓库，并作为远程仓库的master分支，或者作为另外一个名叫test的分支，如下：<br/>
`$git push origin test:master`         // 提交本地test分支作为远程的master分支<br/>
`$git push origin test:test `             // 提交本地test分支作为远程的test分支<br/>

#分支(branch)操作相关命令<br/>
查看本地分支：`$ git branch`<br/>
查看远程分支：`$ git branch -r`<br/>
创建本地分支：`$ git branch [name] `----注意新分支创建后不会自动切换为当前分支<br/>
切换分支：`$ git checkout [name]`<br/>
创建新分支并立即切换到新分支：`$ git checkout -b [name]`<br/>
删除分支：`$ git branch -d [name]` ---- -d选项只能删除已经参与了合并的分支，对于未有合并的分支是无法删除的。如果想强制删除一个分支，可以使用-D选项<br/>
合并分支：`$ git merge [name]` ----将名称为[name]的分支与当前分支合并<br/>
创建远程分支(本地分支push到远程)：`$ git push origin [name]`<br/>
删除远程分支：`$ git push origin :heads/[name] 或 $ gitpush origin :[name] `<br/>