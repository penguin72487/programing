from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import Select
import time
driver = webdriver.Chrome("C:\\chromedriver.exe")
driver.get('https://webaps.nuk.edu.tw/inquiry_student/User_Login.aspx')
username = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.NAME, 'txtBox_Account'))
)
password = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.NAME, 'txtBox_Password'))
)
login = driver.find_element_by_xpath('//*[@id="btn_login"]')
username.clear()
password.clear()
username.send_keys('B1105125')
password.send_keys('jeffrey1680')
login.click()

# print(driver.page_source)
# 從原本的網頁登入後，顯示的是frame視窗，所以要切到這個網頁，才有資料
driver.get('https://webaps.nuk.edu.tw/inquiry_student/InquiryHead.aspx')
option = Select(driver.find_element_by_name('ConoDDList'))
time.sleep(1)


# selenium 爬 value
List1 = []
for i in range(1, 20):
    try:
        # driver.find_elements_by_tag_name('option')[i] != None
        col = driver.find_elements_by_tag_name('option')[i]
        value = col.get_attribute("value")
        print(value)
        List1.append(value)
    except:
        break

# 選 課
for i in List1:
    option.select_by_value(i)
    # print(i)
    enter = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
    enter.click()
# 填表單
    try:
        driver.switch_to.window(driver.window_handles[1])
        click1 = driver.find_element_by_xpath('//*[@id="S1,5"]')
        click1.click()
        choose = driver.execute_script('document.getElementById("S1,5").checked = true')
        # 第一頁
        try:
            choose = driver.execute_script('document.getElementById("S2,2").checked = true')
            choose = driver.execute_script('document.getElementById("S3,5").checked = true')
            choose = driver.execute_script('document.getElementById("R1,5").checked = true')
            choose = driver.execute_script('document.getElementById("R2,5").checked = true')
            choose = driver.execute_script('document.getElementById("R3,5").checked = true')
            choose = driver.execute_script('document.getElementById("R4,5").checked = true')
            choose = driver.execute_script('document.getElementById("R5,5").checked = true')
            choose = driver.execute_script('document.getElementById("R6,5").checked = true')
            choose = driver.execute_script('document.getElementById("R7,5").checked = true')
            choose = driver.execute_script('document.getElementById("R8,5").checked = true')
            choose = driver.execute_script('document.getElementById("R9,5").checked = true')
            choose = driver.execute_script('document.getElementById("R10,5").checked = true')
            choose = driver.execute_script('document.getElementById("ctl14_0").checked = true')
            choose = driver.execute_script('document.getElementById("ctl15_0").checked = true')
            choose = driver.execute_script('document.getElementById("ctl16_0").checked = true')
            choose = driver.execute_script('document.getElementById("ctl17_0").checked = true')
            try:
                choose = driver.execute_script('document.getElementById("ctl18_0").checked = true')
                try:
                    choose = driver.execute_script('document.getElementById("ctl19_0").checked = true')
                    try:
                        choose = driver.execute_script('document.getElementById("ctl20_0").checked = true')
                        try:
                            choose = driver.execute_script('document.getElementById("ctl21_0").checked = true')
                            try:
                                choose = driver.execute_script('document.getElementById("ctl22_0").checked = true')
                                submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
                                submit.click()
                            except:
                                submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
                                submit.click()
                        except:
                            submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
                            submit.click()
                    except:
                        submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
                        submit.click()

                except:
                    submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
                    submit.click()
            except:
                submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
                submit.click()

            submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
            submit.click()

            # 第一頁填完 判斷有沒有第二頁
            try:
                choose = driver.execute_script('document.getElementById("S1,5").checked = true')
                choose = driver.execute_script('document.getElementById("S2,5").checked = true')
                choose = driver.execute_script('document.getElementById("R1,5").checked = true')
                choose = driver.execute_script('document.getElementById("R2,5").checked = true')
                choose = driver.execute_script('document.getElementById("R3,5").checked = true')
                choose = driver.execute_script('document.getElementById("R4,5").checked = true')
                submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
                submit.click()
                driver.switch_to.window(driver.window_handles[0])
            except:
                driver.switch_to.window(driver.window_handles[0])
        # 第二頁
        except:

            driver.get('https://webaps.nuk.edu.tw/inquiry_student/InquiryDataTA_C.aspx')
            click1 = driver.find_element_by_xpath('//*[@id="S1,5"]')
            click1.click()
            click1 = driver.find_element_by_xpath('//*[@id="S2,5"]')
            click1.click()
            click1 = driver.find_element_by_xpath('//*[@id="R1,5"]')
            click1.click()
            click1 = driver.find_element_by_xpath('//*[@id="R2,5"]')
            click1.click()
            click1 = driver.find_element_by_xpath('//*[@id="R3,5"]')
            click1.click()
            click1 = driver.find_element_by_xpath('//*[@id="R4,5"]')
            click1.click()
            submit = driver.find_element_by_xpath('//*[@id="btnConfirm"]')
            submit.click()
            driver.switch_to.window(driver.window_handles[0])

    except:
        driver.switch_to.window(driver.window_handles[0])

check = driver.find_element_by_xpath('//*[@id="btnQueryData"]')
check.click()

time.sleep(5)
driver.quit()