create OR REPLACE database epytodo;
USE epytodo;
DROP TABLE IF EXISTS user;
DROP TABLE IF EXISTS task;
DROP TABLE IF EXISTS user_has_task;
CREATE OR REPLACE TABLE user (
    user_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(20) NOT NULL,
    password VARCHAR(20) NOT NULL
);
CREATE OR REPLACE TABLE task (
    task_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(20) NOT NULL,
    begin DATE DEFAULT CURRENT_TIMESTAMP,
    end DATE DEFAULT NULL,
    status ENUM('not started', 'in progress', 'done') DEFAULT 'not started'
);
CREATE OR REPLACE TABLE user_has_task (
    fk_user_id INT NOT NULL,
    FOREIGN KEY (fk_user_id)
        REFERENCES user(user_id),
    fk_task_id INT NOT NULL,
    FOREIGN KEY (fk_task_id)
        REFERENCES task(task_id)
);