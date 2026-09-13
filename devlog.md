---
title: "Devlog"
layout: reference
nav_order: 12
description: "Dated posts about what has changed in TaystJK and why."
---

<div class="page-heading" markdown="1">
<p class="eyebrow">Devlog</p>

# Devlog

<p class="page-lede">Notes on what has changed and why, newest first. Subscribe with the <a href="/TaystJK/devlog/feed.xml">Atom feed</a>.</p>
</div>

{% assign posts = site.devlog | sort: "date" | reverse %}
{% if posts.size == 0 %}

No posts yet.

{% else %}
<ul class="devlog-list">
{%- for post in posts %}
  <li>
    <a class="devlog-title" href="{{ post.url | relative_url }}">{{ post.title }}</a>
    <time class="devlog-date" datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%-d %B %Y" }}</time>
    {%- if post.description %}
    <p class="devlog-summary">{{ post.description }}</p>
    {%- endif %}
  </li>
{%- endfor %}
</ul>
{% endif %}
