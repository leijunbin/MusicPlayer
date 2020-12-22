#include "styleSheet.h"
#include "headerfile.h"

QString styleSheet_byslef::MenuStyle(){
    return "QMenu {"
           "background-color : rgb(253,253,254);"
        "padding:5px;"
        "border-radius:15px;"
       "}"
       "QMenu::item {"
           "font-size:8pt;"
           "color: rgb(0,0,0);"
           "background-color:rgb(253,253,254);"
           "padding: 8px 25px 6px 10px;"
           "margin: 4px 1px;"
       "}"
       "QMenu::item:selected {"
           "background-color : rgb(236,236,237);"
       "}"
       "QMenu::icon:checked {"
           "background: rgb(253,253,254);"
           "position: absolute;"
           "top: 1px;"
           "right: 1px;"
           "bottom: 1px;"
           "left: 1px;"
       "}"
       "QMenu::icon:checked:selected {"
           "background-color : rgb(236,236,237);"
           "background-image: url(:/space_selected.png);"
       "}"
       "QMenu::separator {"
           "height: 2px;"
           "background: rgb(235,235,236);"
           "margin-left: 10px;"
           "margin-right: 10px;"
       "}";
}

QString styleSheet_byslef::PauseStyle(){
    return "QPushButton"
        " {"
     "background-image:url(:/image/image/image_normal/pause.png);"
    "   background-repeat:no-repeat;"
    "  background-position:center center;"
    "   border:none;"

 "    }"

     "QPushButton:hover{"
   "  background-repeat:no-repeat;"
  "   background-position:center center;"
  "background-image:url(:/image/image/image_hover/pause_hover.png);"

    " }"
    " QPushButton:pressed{"
     "background-repeat:no-repeat;"
    " background-position:center center;"
    " background-image:url(:/image/image/image_normal/pause.png);"
      "}";
}

QString styleSheet_byslef::PlayStyle(){
    return "QPushButton"
   " {"
   "background-image:url(:/image/image/image_normal/play.png);"
 "   background-repeat:no-repeat;"
  "  background-position:center center;"
 "   border:none;"

"    }"

    "QPushButton:hover{"
  "  background-repeat:no-repeat;"
 "   background-position:center center;"
 "background-image:url(:/image/image/image_hover/play_hover.png);"

   " }"
   " QPushButton:pressed{"
    "background-repeat:no-repeat;"
   " background-position:center center;"
   " background-image:url(:/image/image/image_normal/play.png);"

     "}";
}

QString styleSheet_byslef::VoiceStyle(){
    return "QPushButton"
       " {"
       "background-image:url(:/image/image/image_normal/music-voice.png);"
     "   background-repeat:no-repeat;"
      "  background-position:center center;"
     "   border:none;"

    "    }"

        "QPushButton:hover{"
      "  background-repeat:no-repeat;"
     "   background-position:center center;"
     "background-image:url(:/image/image/image_hover/music-voice_hover.png);"

       " }"
       " QPushButton:pressed{"
        "background-repeat:no-repeat;"
       " background-position:center center;"
       " background-image:url(:/image/image/image_normal/music-voice.png);"
       "}";
}

QString styleSheet_byslef::NoVoiceStyle(){
    return "QPushButton"
       " {"
       "background-image:url(:/image/image/image_normal/none-music.png);"
     "   background-repeat:no-repeat;"
      "  background-position:center center;"
     "   border:none;"

    "    }"

        "QPushButton:hover{"
      "  background-repeat:no-repeat;"
     "   background-position:center center;"
     "background-image:url(:/image/image/image_hover/none-music_hover.png);"

       " }"
       " QPushButton:pressed{"
        "background-repeat:no-repeat;"
       " background-position:center center;"
       " background-image:url(:/image/image/image_normal/none-music.png);"
         "}";
}

QString styleSheet_byslef::listWidgetStyle(){
    return "QScrollBar:vertical"
           "{"
                   "width:8px;"
                   "background-color:transparent;"
                   "margin:0px,0px,0px,0px;"
                  " padding-top:12px;   /*上预留位置*/"
                  " padding-bottom:12px;    /*下预留位置*/"
               "}"


             "  QScrollBar::handle:vertical"
              " {"
                   "width:8px;"
                  " background-color:rgba(255,255,255,0.2);"
                  " border-radius:4px;"
                  " min-height:20px;"
              " }"


           "    QScrollBar::handle:vertical:hover"
            "   {"
             "      width:9px;"
                  " background-color:rgba(255,255,255,0.5);"
                "   border-radius:4px;"
              "     min-height:20;"
             "  }"

             "  QScrollBar::add-line:vertical"
             "  {"
                  " height:12px;"
              "     width:10px;"
           "        border-image:url(:/selectfile/scroll/3.png);"
                  " subcontrol-position:bottom;"
           "    }"

           "    QScrollBar::sub-line:vertical"
           "    {"
           "        height:12px;"
                   "width:10px;"
                "   border-image:url(:/selectfile/scroll/1.png);"
                   "subcontrol-position:top;"
            "   }"
           "    QScrollBar::add-line:vertical:hover"
            "   {"
                  " height:12px;"
                   "width:10px;"
                  " border-image:url(:/selectfile/scroll/4.png);"
                   "subcontrol-position:bottom;"
              " }"


              " QScrollBar::sub-line:vertical:hover"
              " {"
              "     height:12px;"
                 "  width:10px;"
                 "  border-image:url(:/selectfile/scroll/2.png);"
                  " subcontrol-position:top;"
              " }"

              " QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
              " {"
                  " background-color:transparent;"
                "   border-radius:4px;"
               "}";
}

QString styleSheet_byslef::RandomStyle(){
    return "QPushButton"
       " {"
       "background-image:url(:/image/image/image_normal/play-random.png);"
     "   background-repeat:no-repeat;"
      "  background-position:center center;"
     "   border:none;"

    "    }"

        "QPushButton:hover{"
      "  background-repeat:no-repeat;"
     "   background-position:center center;"
     "background-image:url(:/image/image/image_hover/play-random_hover.png);"

       " }"
       " QPushButton:pressed{"
        "background-repeat:no-repeat;"
       " background-position:center center;"
       " background-image:url(:/image/image/image_normal/play-random.png);"
       "}";
}

QString styleSheet_byslef::LoopStyle(){
    return "QPushButton"
       " {"
       "background-image:url(:/image/image/image_normal/loop.png);"
     "   background-repeat:no-repeat;"
      "  background-position:center center;"
     "   border:none;"

    "    }"

        "QPushButton:hover{"
      "  background-repeat:no-repeat;"
     "   background-position:center center;"
     "background-image:url(:/image/image/image_hover/loop_hover.png);"

       " }"
       " QPushButton:pressed{"
        "background-repeat:no-repeat;"
       " background-position:center center;"
       " background-image:url(:/image/image/image_normal/loop.png);"
         "}";
}

QString styleSheet_byslef::LoopOneStyle(){
    return "QPushButton"
       " {"
       "background-image:url(:/image/image/image_normal/loop-one.png);"
     "   background-repeat:no-repeat;"
      "  background-position:center center;"
     "   border:none;"

    "    }"

        "QPushButton:hover{"
      "  background-repeat:no-repeat;"
     "   background-position:center center;"
     "background-image:url(:/image/image/image_hover/loop-one_hover.png);"

       " }"
       " QPushButton:pressed{"
        "background-repeat:no-repeat;"
       " background-position:center center;"
       " background-image:url(:/image/image/image_normal/loop-one.png);"
         "}";
}

QString styleSheet_byslef::ButtonStyle(){
    return "QPushButton{"
           "width:100px;"
           "height:32px;"
           "text-align:center;"
           "line-height:32px;"
           "background-color: deepskyblue;"
           "border-style:solid;"
           "border-width: 1px;"
           "border-radius: 6px;"
           "border-color: deepskyblue;"
           "font: bold 14px;"
           "color :white;"
           "}"
           "QPushButton:hover{"
           "background-color: aqua;"
           "color: white;"
           "border-color:aqua;"
           "}"
           "QPushButton:pressed{"
      "background-color:  white;"
           "border-color:white;"
           "color:deepskyblue;"
           "}";
}

QString styleSheet_byslef::ProgressDialogStyle(){
    return "QProgressBar{border: 1px solid grey;border-radius: 5px;text-align: center;background-color:rgba(255,255,255,150);}"
           "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}";
}

QString styleSheet_byslef::LikeMusicStyle(){
    return "QPushButton"
       " {"
       "background-image:url(:/image/image/image_normal/likemusic.png);"
     "   background-repeat:no-repeat;"
      "  background-position:center center;"
     "   border:none;"

    "    }"

        "QPushButton:hover{"
      "  background-repeat:no-repeat;"
     "   background-position:center center;"
     "background-image:url(:/image/image/image_hover/likemusic_hover.png);"

       " }"
       " QPushButton:pressed{"
        "background-repeat:no-repeat;"
       " background-position:center center;"
       " background-image:url(:/image/image/image_normal/likemusic.png);"
         "}";
}

QString styleSheet_byslef::NoLikeMusicStyle(){
    return "QPushButton"
       " {"
       "background-image:url(:/image/image/image_normal/nolikemusic.png);"
     "   background-repeat:no-repeat;"
      "  background-position:center center;"
     "   border:none;"

    "    }"

        "QPushButton:hover{"
      "  background-repeat:no-repeat;"
     "   background-position:center center;"
     "background-image:url(:/image/image/image_hover/nolikemusic_hover.png);"

       " }"
       " QPushButton:pressed{"
        "background-repeat:no-repeat;"
       " background-position:center center;"
       " background-image:url(:/image/image/image_normal/nolikemusic.png);"
         "}";
}

QString styleSheet_byslef::pushButton_12_normalStyle(){
    return "QPushButton"
           "{"
           "background-image: url(:/image/image/image_normal/music.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:none;"

           "}"

           "QPushButton:hover{"

               "background-image: url(:/image/image/image_hover/music_hover.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"


           "}"
           "QPushButton:pressed{"
           "background-image: url(:/image/image/image_normal/music.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"

           "}";
}

QString styleSheet_byslef::pushButton_12_hoverStyle(){
    return "QPushButton"
           "{"
           "background-image: url(:/image/image/image_hover/music_hover.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:none;"

           "}"

           "QPushButton:hover{"

               "background-image: url(:/image/image/image_hover/music_hover.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"


           "}"
           "QPushButton:pressed{"
           "background-image: url(:/image/image/image_normal/music.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"

           "}";
}

QString styleSheet_byslef::pushButton_13_normalStyle(){
    return " QPushButton"
             "{"
             "background-image: url(:/image/image/image_normal/like.png);"
             "background-repeat:no-repeat;"
             "background-position:center center;"
             "border:none;"

             "}"

             "QPushButton:hover{"

                 "background-image: url(:/image/image/image_hover/like_hover.png);"
             "background-repeat:no-repeat;"
             "background-position:center center;"


             "}"
             "QPushButton:pressed{"
             "background-image: url(:/image/image/image_normal/like.png);"
             "background-repeat:no-repeat;"
             "background-position:center center;"

             "}";
}

QString styleSheet_byslef::pushButton_13_hoverStyle(){
    return " QPushButton"
             "{"
             "background-image: url(:/image/image/image_hover/like_hover.png);"
             "background-repeat:no-repeat;"
             "background-position:center center;"
             "border:none;"

             "}"

             "QPushButton:hover{"

                 "background-image: url(:/image/image/image_hover/like_hover.png);"
             "background-repeat:no-repeat;"
             "background-position:center center;"


             "}"
             "QPushButton:pressed{"
             "background-image: url(:/image/image/image_normal/like.png);"
             "background-repeat:no-repeat;"
             "background-position:center center;"

             "}";
}

QString styleSheet_byslef::pushButton_14_normalStyle(){
    return "QPushButton"
           "{"
           "background-image: url(:/image/image/image_normal/list.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:none;"

           "}"

           "QPushButton:hover{"

               "background-image: url(:/image/image/image_hover/list_hover.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"


           "}"
           "QPushButton:pressed{"
           "background-image: url(:/image/image/image_normal/list.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"

           "}";
}

QString styleSheet_byslef::pushButton_14_hoverStyle(){
    return  "QPushButton"
            "{"
            "background-image: url(:/image/image/image_hover/list_hover.png);"
            "background-repeat:no-repeat;"
            "background-position:center center;"
            "border:none;"

            "}"

            "QPushButton:hover{"

                "background-image: url(:/image/image/image_hover/list_hover.png);"
            "background-repeat:no-repeat;"
            "background-position:center center;"


            "}"
            "QPushButton:pressed{"
            "background-image: url(:/image/image/image_normal/list.png);"
            "background-repeat:no-repeat;"
            "background-position:center center;"

            "}";
}

QString styleSheet_byslef::pushButton_15_normalStyle(){
    return "QPushButton"
           "{"
           "background-image: url(:/image/image/image_normal/play-resently.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:none;"

           "}"

           "QPushButton:hover{"

               "background-image: url(:/image/image/image_hover/play-resently_hover.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"


           "}"
           "QPushButton:pressed{"
           "background-image: url(:/image/image/image_normal/play-resently.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"

           "}";
}

QString styleSheet_byslef::pushButton_15_hoverStyle(){
    return "QPushButton"
           "{"
           "background-image: url(:/image/image/image_hover/play-resently_hover.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"
           "border:none;"

           "}"

           "QPushButton:hover{"

               "background-image: url(:/image/image/image_hover/play-resently_hover.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"


           "}"
           "QPushButton:pressed{"
           "background-image: url(:/image/image/image_normal/play-resently.png);"
           "background-repeat:no-repeat;"
           "background-position:center center;"

           "}";
}
