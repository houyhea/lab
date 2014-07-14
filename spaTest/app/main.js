/**
 * Created by houyhea on 14-7-4.
 */
require.config({
    paths:{
        "text":"../lib/require.text",
        "css":"../lib/require.css"
    }
})
require(["app"],function(app){
    app.run();
})