## Drone Delivery System Simulation
This is a compiled version of the CSCI 3081 drone simulation for Team-86
  

## Download Images
 ```bash
docker pull said0042/sim
  ```

## Run Simulation
 ```bash
docker run --name=drone_sim -p 127.0.0.1:8082:8081 -d  said0042/sim
```

Navigate in the browser to view:

* Simulation - [http://127.0.0.1:8082](http://127.0.0.1:8082)
*Documentation - [http://127.0.0.1:8082/docs/](http://127.0.0.1:8082/docs/)

The "Kill Simulation" button will kill the current simulation and restart the web server so you can rerun the simulation. 
The web page will need to be refreshed.

## Stop Simulation
```bash
docker kill drone_sim
docker rm drone_sim
```
