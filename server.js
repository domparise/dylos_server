var spark = require('spark')

spark.login({username: 'user@email.com', password: 'pass'});

spark.getDevice('deviceName', function(err, device) {
    console.log(device.name + ' connected');
    console.log('time: ' + Date.now())

    device.subscribe('dust_count', function(data) {
        data = JSON.parse(data.data)
        console.log(data)
    })

})
