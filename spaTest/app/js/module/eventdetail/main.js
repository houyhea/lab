/**
 * Created by houyhea on 14-7-4.
 */
define(['text!./layout.html','text!./item.html','css!./style.css','css!./../../../skin/default/base.css'],function(layouttpl,itemtpl){
    return {
        render:function(dom){
            dom.html(layouttpl);


        }
    }
})