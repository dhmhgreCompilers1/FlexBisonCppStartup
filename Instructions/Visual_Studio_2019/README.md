### Create your workspace...

1. Download [Win flex-bison](https://sourceforge.net/projects/winflexbison/).
2. Extract **win_flex_bison-latest.zip** to **C:\FlexBison**.
3. Open **Start Menu**, search "**PATH**" and click on **Edit Environment Variables**  
or right-click on **My computer**, click **Properties** and click **Advanced system settings** on the left, it's the same thing.
4. Click **Environment Variables** and in the **System variables** box select **Path** and click **Edit**.
5. You have to add manually FlexBison's path **C:\FlexBison**.
6. **Log off** and **Log on** to your computer, don't Change Uuser or Lock.
7. Open **cmd** (I think all we know how to open cmd) and enter the word "**path**", if you see FlexBison's path your are good to go.

8. Open **Visual Studio 2019** and click **File -> New -> Project** and select **Windows Desktop Wizard**.
9. Set a name for your project.
10. It is important to select **Empty project** box, **only**.

    ####Steps 11 and 12 have to be done before adding any file in your project**

11. Go to **View -> Solution Explorer** and right-click on your project and click **Build Dependencies -> Build Customizations**.
12. Click **Find Existing** and find **C:\FlexBison\custom_build_rules\win_flex_bison_custom_build.targets**, when you add it to the list, you need to check the box.