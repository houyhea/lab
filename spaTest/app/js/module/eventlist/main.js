/**
 * Created by houyhea on 14-7-4.
 */
define(['text!./layout.html','text!./item.html','css!./style.css','css!./../../../skin/default/base.css'],function(layouttpl,itemtpl){
    return {
        render:function(dom){
           dom.html(layouttpl);
            var btnb=dom.find("#loadbtnb");
            btnb.on("click",function(){
                var body2=$("#tbody2");
                require(["js/module/eventdetail/main"],function(eventdetail){
                    eventdetail.render(body2);
                });
            });
        }
    }
})