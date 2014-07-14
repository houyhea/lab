/**
 * Created by houyhea on 14-7-4.
 */
define(function(){
    return {
        run:function(){
            //alert("app run.");
        var b=$("#tbody");
            var btna=$("#loadabtn");
            btna.on("click",function(){
                require(["js/module/eventlist/main"],function(eventlist)
                {
                    eventlist.render(b);
                });
            });
        }
    }
})