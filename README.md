# SIMS
# 新手第一次提交代码
在github里新建一个仓库（repository）

如果是第一次使用git，就需要连接你的github账号
git config --global user.name "@@@"     (GitHub相对应的帐号名称)
git config --global user.email "123@163.com"  （GitHbu相对应的邮箱帐号）

然后cd到你的代码文件夹下面，依次执行：
git init
git remote add origin http:
git add .
git commit -m "备注信息"
git push -u origin --all

以后每次想提交代码的时候就可以想查询状态：
git status
然后查看需要提交的东西：
git add .
输入提交信息
git commit -m "XX"
push到master
git push origin master
pull到master
git pull origin master

#常用命令
下载仓库：$ git clone git://github.com/jquery/jquery.git
查看远程仓库：$ git remote -v
添加远程仓库：$ git remote add [name] [url]
删除远程仓库：$ git remote rm [name]
修改远程仓库：$ git remote set-url --push [name] [newUrl]
拉取远程仓库：$ git pull [remoteName] [localBranchName]
推送远程仓库：$ git push [remoteName] [localBranchName]

如果想把本地的某个分支test提交到远程仓库，并作为远程仓库的master分支，或者作为另外一个名叫test的分支，如下：
$git push origin test:master         // 提交本地test分支作为远程的master分支
$git push origin test:test              // 提交本地test分支作为远程的test分支

#分支(branch)操作相关命令
查看本地分支：$ git branch
查看远程分支：$ git branch -r
创建本地分支：$ git branch [name] ----注意新分支创建后不会自动切换为当前分支
切换分支：$ git checkout [name]
创建新分支并立即切换到新分支：$ git checkout -b [name]
删除分支：$ git branch -d [name] ---- -d选项只能删除已经参与了合并的分支，对于未有合并的分支是无法删除的。如果想强制删除一个分支，可以使用-D选项
合并分支：$ git merge [name] ----将名称为[name]的分支与当前分支合并
创建远程分支(本地分支push到远程)：$ git push origin [name]
删除远程分支：$ git push origin :heads/[name] 或 $ gitpush origin :[name] 
