# Курсовой проект «Симулятор гонок»

Курсовой проект — простейшая реализация симулятора гонок для фэнтезийных транспортных средств (ТС).

## Содержание

### 1. Правила игры
Все ТС делятся на два типа:
 - наземные;
 - воздушные.
 
В симуляторе есть несколько видов ТС:
 - верблюд (наземное);
 - верблюд-быстроход (наземное);
 - кентавр (наземное);
 - ботинки-вездеходы (наземное);
 - ковёр-самолёт (воздушное);
 - орёл (воздушное);
 - метла (воздушное).

У всех ТС есть заранее заданная скорость.

В симуляторе есть несколько видов гонок:
 - только для наземных ТС;
 - только для воздушных ТС;
 - для наземных и воздушных ТС.

#### Наземные ТС
Наземные ТС не могут двигаться непрерывно: после определённого времени им нужно отдыхать. У каждого вида наземного ТС время движения своё. Время отдыха у каждого наземного ТС также различается и зависит от того, какая по счёту эта остановка.

##### Пример 
Скорость ТС равна 100 км/ч, дистанция равна 1000 км, время движения до отдыха равно 6 ч, длительность отдыха равна 3 ч. В таком случае ТС пройдёт дистанцию за 1000 / 100 = 10 ч. Так как время движения до отдыха равно 6 часов, то по пути ТС нужно будет отдохнуть 1 раз. Итоговое время составит: 10 + 3 = 13 ч.

Сводная таблица характеристик для каждого наземного ТС:

| Вид ТС           | Скорость | Время движения<br>до отдыха| Длительность отдыха
|------------------|----------|----------------------------|--------------------
| Верблюд          | 10       | 30                         | Первый раз: 5<br>Все последующие разы: 8
| Верблюд-быстроход| 40       | 10                         | Первый раз: 5<br>Второй раз: 6.5<br>Все последующие разы: 8
| Кентавр          | 15       | 8                          | Всегда 2
| Ботинки-вездеходы| 6        | 60                         | Первый раз: 10<br>Все последующие разы: 5

#### Воздушные ТС
Воздушные ТС двигаются непрерывно. Так как они могут облетать препятствия, каждое воздушное ТС имеет собственный коэффициент сокращения расстояния: то есть для каждого воздушного ТС дистанция, которую нужно пройти, уменьшается. Коэффициент сокращения расстояния может зависеть от дистанции.

##### Пример 
Если у воздушного ТС коэффициент сокращения расстояния равен 5%, то вместо дистанции в 1000 км ему нужно пройти дистанцию в 1000 * 0.95 = 950 км.

Сводная таблица характеристик для каждого воздушного ТС:

| Вид ТС           | Скорость | Коэффициент сокращения расстояния
|------------------|----------|----------------------------------
| Ковёр-самолёт    | 10       | Если расстояние меньше 1000 — без сокращения<br>Если расстояние меньше 5000 — 3%<br>Если расстояние меньше 10000 — 10%<br>Если расстояние больше или равно 10000 — 5%
| Орёл             | 8        | Всегда 6%
| Метла            | 20       | Увеличивается на 1% за каждую 1000 у.е. расстояния<br>Например, для расстояния 5600 коэффициент будет 5%

### 2. Требования к решению

Требования по функционированию программы:
1. При старте программы пользователю должен быть предложен выбор типа гонки.
2. После выбора типа гонки пользователь должен указать расстояние для этой гонки.
3. Пользователю должна быть предоставлена возможность зарегистрировать ТС на гонку.
4. Можно регистрировать не более одного экземпляра для каждого вида ТС.
5. На гонку должно быть зарегистрировано хотя бы два вида ТС.
6. Нельзя зарегистрировать на наземную гонку воздушное ТС, а на воздушную гонку наземное ТС.
7. После завершения регистрации пользователь может либо зарегистрировать ещё ТС, либо начать гонку.
8. Сама гонка происходит мгновенно. Пользователю выводится результат гонки — ТС-участники гонки и их время.
9. Результаты участников должны выводиться по возрастанию времени: самый быстрый оказывается вверху списка, самый медленный — внизу.
10. Вместе с результатами гонки пользователю должен быть предложен выбор: провести ещё одну гонку (программа стартует заново) или выйти из программы.

Требования к структуре и реализации программы:
1. Для реализации ТС и гонок должны быть использованы иерархии классов.
2. Для каждого класса должна быть создана пара «заголовочный файл + файл исходного кода».
3. Классы ТС, гонок и другие вспомогательные классы должны находиться в отдельной динамической библиотеке (DLL).
4. В основном проекте (.exe) должен находиться код для взаимодействия с пользователем и использование классов из вашей библиотеки в ответ на действия пользователя.
5. Классы библиотеки не должны самостоятельно выводить данные на консоль.

# Course project “Racing simulator”

The course project is the simplest implementation of a racing simulator for fantasy vehicles.

## Content

### 1. Rules of the game
All vehicles are divided into two types:
  - ground;
  - air.
 
There are several types of vehicles in the simulator:
  - camel (terrestrial);
  - fast camel (ground);
  - centaur (ground);
  - all-terrain boots (ground);
  - flying carpet (air);
  - eagle (air);
  - broom (air).

All vehicles have a preset speed.

The simulator has several types of races:
  - only for ground vehicles;
  - only for air vehicles;
  - for ground and air vehicles.

#### Ground vehicles
Ground vehicles cannot move continuously: after a certain time they need to rest. Each type of ground vehicle has its own travel time. The rest time for each ground vehicle also differs and depends on what kind of stop it is.

##### Example
The speed of the vehicle is 100 km/h, the distance is 1000 km, the travel time before rest is 6 hours, the duration of rest is 3 hours. In this case, the vehicle will cover the distance in 1000 / 100 = 10 hours. Since the travel time before rest is 6 hours , then the vehicle will need to rest once along the way. The total time will be: 10 + 3 = 13 hours.

Summary table of characteristics for each ground vehicle:

| Type of vehicle  | Speed    | Movement time before rest| Duration of rest
|------------------|----------|-----------------------------|--------------------
| Camel            | 10       | 30                          | First time: 5<br>All subsequent times: 8
| Swift camel      | 40       | 10                          | First time: 5<br>Second time: 6.5<br>All subsequent times: 8
| Centaur          | 15       | 8                           | Always 2
| All-terrain boots| 6        | 60                          | ПFirst time: 10<br>All subsequent times: 5

#### Air vehicles
Air vehicles move continuously. Since they can fly around obstacles, each air vehicle has its own distance reduction factor: that is, for each air vehicle, the distance that needs to be covered is reduced. The distance reduction factor may depend on the distance.

##### Example
If an air vehicle has a distance reduction coefficient of 5%, then instead of a distance of 1000 km, it needs to cover a distance of 1000 * 0.95 = 950 km.

Summary table of characteristics for each air vehicle:

| Type of vehicle  | Speed    | Distance reduction factor
|------------------|----------|----------------------------------
| Magic carpet     | 10       | If the distance is less than 1000 - no reduction<br>If the distance is less than 5000 - 3%<br>If the distance is less than 10000 - 10%<br>If the distance is greater than or equal to 10000 - 5%
| Eagle            | 8        | Always 6%
| Broom            | 20       | Increases by 1% for every 1000 USD. distances<br>For example, for a distance of 5600 the coefficient will be 5%

### 2. Solution requirements

Requirements for the program to function:
1. When starting the program, the user should be offered a choice of race type.
2. After selecting the race type, the user must specify the distance for that race.
3. The user must be given the opportunity to register the vehicle for the race.
4. You can register no more than one copy for each type of vehicle.
5. At least two types of vehicles must be registered for the race.
6. You cannot register an air vehicle for a ground race, or a ground vehicle for an air race.
7. After registration is completed, the user can either register another vehicle or start the race.
8. The race itself happens instantly. The result of the race is displayed to the user - the vehicles participating in the race and their time.
9. The results of the participants should be displayed in ascending order of time: the fastest is at the top of the list, the slowest is at the bottom.
10. Along with the results of the race, the user should be offered a choice: to run another race (the program starts again) or exit the program.

Requirements for the structure and implementation of the program:
1. To implement vehicles and races, class hierarchies must be used.
2. For each class, a pair of “header file + source code file” must be created.
3. Vehicle classes, races and other auxiliary classes must be in a separate dynamic link library (DLL).
4. The main project (.exe) should contain code to interact with the user and use classes from your library in response to user actions.
5. Library classes should not independently output data to the console.