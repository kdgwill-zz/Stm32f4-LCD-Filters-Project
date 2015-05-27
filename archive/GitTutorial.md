To get a local copy onto your computer, just replace USERNAME with the bitbucket user name

```
git clone https://kdgwill@bitbucket.org/kdgwill/el6483-project.git

git clone https://sbk411@bitbucket.org/kdgwill/el6483-project.git

git clone https://vg933@bitbucket.org/kdgwill/el6483-project.git

git clone https://jc6875@bitbucket.org/kdgwill/el6483-project.git
```

Before committing remember to merge any updates from the repo to your local.
```
git remote add --track master upstream https://bitbucket.org/kdgwill/el6483-project.git
```
Then,
```
git pull origin


git fetch origin -v
git fetch upstream -v
git merge upstream/master
```

I have set up a .gitignore file to make the commiting process easier so

```
git add -A
git commit -m"Commit Message"
```
Note: Commit messages should be short active messages such as **Create Library** or **Fix Library Bug**

When you are ready to upload simply run

```
git push -u origin master
```




Johnny's Tips
---
After you clone and make your changes to the documents.  These lines make a branch of the master

where your changes will go and pushes your new branch onto the online repository.

git add Reportname.something

git checkout -b branch_name

git commit -m "description of changes"

git push -u branch_name

To locally go to your master branch

git checkout master

To locally go to your branch

git checkout branch

To locally merge your master with the changes you made in the branch do the following below.

git checkout master

git merge the_branch

To then update your online master

git push -u origin master

To locally merge your branch with the changes made to the master do the following below.

git checkout the_branch

git merge master

To then update your online copy of that branch

git push -u origin the_branch
